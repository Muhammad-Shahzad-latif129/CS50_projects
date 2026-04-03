import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from sqlalchemy import values
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    
    stocks = db.execute("SELECT symbol, SUM(shares) AS total_shares FROM transactions WHERE person_id == ? GROUP BY symbol HAVING total_shares > 0", session["user_id"])

    user_row = db.execute('SELECT cash FROM users WHERE id == ?', session["user_id"])
    cash = user_row[0]["cash"]
    
    grand_total = cash
    for stock in stocks:
        qoute = lookup(stock["symbol"])
        stock["symbol"] = qoute["symbol"]
        stock["price"] = qoute["price"] #current price
        stock["total_price"] = qoute["price"] * stock["total_shares"] #current total price
        grand_total += stock["total_price"]


    # grand_total += cash

    return render_template("index.html", stocks=stocks, grand_total=grand_total, cash=cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("must provide username", 403)
        if not request.form.get("shares"):
            return apology("must provide shares", 403)
        
        # Convert shares to int to avoid math errors
        
        shares = request.form.get("shares")
        if not shares.isdigit():
            return apology("invalid shares")
        
        shares = int(shares)
        if shares <= 0:
            return apology("share's value must be positive")
        
        values = lookup(request.form.get("symbol"))
        if not values:
            return apology("invalid symbol")
        
        
        row = db.execute("SELECT * FROM users WHERE id == ?", session["user_id"])
        # Total cost of shares to buy, calculted by multiplying price of share with number of shares
        total_cost = values["price"] * shares
        if total_cost > float(row[0]["cash"]):
            return apology("low budget")

        symbol = values["symbol"]
        price = values["price"]
        person_id = session["user_id"]

        db.execute("INSERT INTO transactions (person_id, symbol, shares, price) VALUES(?, ?, ?, ?)", person_id, symbol, shares, price)

          # SUBTRACT the cash from users table 
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", 
        total_cost, session["user_id"])

        flash("Bought!")
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    rows = db.execute("SELECT symbol, shares, price, timestamp FROM transactions WHERE person_id == ?", session["user_id"])
    return render_template("history.html", rows=rows)
    

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        values = lookup(request.form.get("symbol"))
        if not values:
            return apology("invalid symbol")
        values["price"] = usd(values["price"])
        return render_template("quoted.html", values=values) 
    
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)
        
        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)
        
        elif not request.form.get("confirmation"):
            return apology("must provide confirm password")
        
        # Password equal confirm password
        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("password donot match")
        
        password = generate_password_hash(request.form.get("password"))
        try:
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", request.form.get("username"), password) 
        except ValueError:
            return apology("username already exist")
        
        return redirect("/login")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":

        symbol = request.form.get("symbol")
        if not (request.form.get("shares").isdigit()):
            return apology("invalid shares")
        
        shares_to_sell = int(request.form.get("shares"))

        if not symbol:
            return apology("must provide symbol")
        
        if not request.form.get("shares"):
            return apology("must provide number of shares")
        
        if shares_to_sell <= 0:
            return apology("shares must be positive")
        
        rows = db.execute("SELECT SUM(shares) AS total_shares FROM transactions WHERE person_id == ? AND symbol == ? GROUP BY symbol", session["user_id"], symbol)

        if not rows or rows[0]["total_shares"] < shares_to_sell:
            return apology("not enough shares")
        
        if int(request.form.get("shares")) <= 0 :
            return apology("share's value must be positive")
         
        qoute = lookup(request.form.get("symbol"))
        price = qoute["price"]
        total_sale_value = price * shares_to_sell

        db.execute("UPDATE users SET cash = cash + ? WHERE id == ?", total_sale_value, session["user_id"])

        db.execute("INSERT INTO transactions (person_id, symbol, shares, price) VALUES (?, ?, ?, ?)", session["user_id"], symbol, -shares_to_sell, price)

        flash("Sold!")

        return redirect("/")
    
    else:
        stocks = db.execute("SELECT symbol FROM transactions WHERE person_id = ? GROUP BY symbol HAVING SUM(shares) > 0", session["user_id"])
      
        return render_template("sell.html",stocks=stocks)
