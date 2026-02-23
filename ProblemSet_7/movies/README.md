_**Problem Overview**_

This project contains my solution to the Movies problem from Problem Set 7 (SQL) in CS50.

The objective of this challenge is to analyze a movie database using SQL to answer questions about films, actors, directors, and ratings. The dataset resembles a simplified version of IMDb, demonstrating how large entertainment platforms organize and query their data.

_**Objectives**_

In this problem, I practiced:

Querying relational databases

Using JOIN operations across multiple tables

Filtering results with conditions

Sorting and limiting results

Applying aggregate functions

Understanding many-to-many relationships

_**Database Structure**_

The database includes several related tables:

movies — information about films

people — actors and directors

stars — relationships between actors and movies

ratings — movie ratings data

These tables illustrate how relational databases model real-world connections.

_**Tasks Performed**_

The problem required writing SQL queries to:

Identify movies featuring specific actors

Find release years of films

Determine highly rated movies

Analyze collaborations between actors

Explore connections between people and films

Each query demonstrates advanced SQL concepts, especially JOINs.

_**How to Run**_

Open a terminal.

Launch SQLite:

**sqlite3 movies.db**

Run the queries:

**.read queries.sql**

_**Key Takeaways**_

This problem demonstrates how relational databases handle complex relationships, such as actors appearing in multiple films and films featuring multiple actors.
