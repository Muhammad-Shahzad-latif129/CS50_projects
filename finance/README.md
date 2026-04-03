📈 CS50 Finance
A full-stack stock trading web application built as part of Harvard's CS50x — Problem Set 9. Users can register, look up real-time stock quotes, buy and sell shares, and track their portfolio — just like a real brokerage, minus the real money.

🚀 Features
·	🔐 User Authentication — Register and log in securely with hashed passwords
·	📊 Real-Time Stock Quotes — Look up live stock prices via the IEX Cloud API
·	💰 Buy & Sell Shares — Simulate purchasing and selling stocks with a starting cash balance of $10,000
·	🗂️ Portfolio Overview — View all currently held stocks, shares, current prices, and total value
·	📜 Transaction History — Full history of every buy and sell transaction
·	💵 Cash Balance Tracking — Always know how much buying power you have left

🛠️ Tech Stack
Layer	Technology
Backend	Python, Flask
Database	SQLite (via CS50 Library)
Frontend	HTML, CSS, Bootstrap 5, Jinja2
API	CS50 Finance API
Auth	Werkzeug password hashing


📁 Project Structure
finance/
├── app.py              # Main Flask application & all routes
├── helpers.py          # Helper functions (login_required, lookup, usd)
├── finance.db          # SQLite database
├── requirements.txt    # Python dependencies
├── static/
│   └── styles.css      # Custom CSS styles
└── templates/
    ├── layout.html     # Base template
    ├── index.html      # Portfolio homepage
    ├── login.html      # Login page
    ├── register.html   # Registration page
    ├── quote.html      # Stock quote form
    ├── quoted.html     # Stock quote result
    ├── buy.html        # Buy stocks form
    ├── sell.html       # Sell stocks form
    └── history.html    # Transaction history


⚙️ Setup & Installation
Prerequisites
·	Python 3.x
·	pip
Steps
1.	
2.	Clone the repository
3.	git clone https://github.com/Muhammad-Shahzad-latif129/finance.git
cd finance

4.	
5.	Install dependencies
6.	pip install -r requirements.txt

7.	This app uses CS50's built-in Finance API(https://finance.cs50.io) which requires no API key. It works ou of the box!
8.	Run the application
9.	flask run

10.	
11.	Open in browser
12.	http://127.0.0.1:5000


🖥️ Usage
Action	How To
Register	Go to /register, create a username & password
Log In	Go to /login with your credentials
Get a Quote	Navigate to Quote, enter a stock symbol (e.g. AAPL)
Buy Stock	Navigate to Buy, enter symbol and number of shares
Sell Stock	Navigate to Sell, choose a stock you own and quantity
View Portfolio	Homepage shows all holdings + current values
View History	Navigate to History to see all past transactions


🗃️ Database Schema
users

| Column   | Type    | Description              |

|----------|---------|--------------------------|

| id       | INTEGER | Primary key              |

| username | TEXT    | Unique username          |

| hash     | TEXT    | Hashed password          |

| cash     | REAL    | Available cash (default $10,000) |
transactions

| Column    | Type    | Description                    |

|-----------|---------|--------------------------------|

| id        | INTEGER | Primary key                    |

| person_id   | INTEGER | Foreign key → users.id         |

| symbol    | TEXT    | Stock ticker symbol            |

| shares    | INTEGER | Number of shares (+ buy/− sell)|

| price     | REAL    | Price per share at transaction |

| timestamp | TEXT    | Date and time of transaction   |

📌 Notes
·	This project was built for educational purposes as part of CS50x.
·	No real money is involved — all trades are simulated.
·	Default starting balance is $10,000 USD.

🏫 Academic Honesty
If you are a current CS50 student, please review the CS50 Academic Honesty Policy before viewing this code. This repository is shared for portfolio purposes only.

👤 Author
Your Name
·	GitHub: @Muhammad-Shahzad-latif129
·	CS50x — Problem Set 9: Finance

📄 License
This project is for educational use. The CS50 course materials are © Harvard University.
