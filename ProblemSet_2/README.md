# 📘 CS50 Problem Set 2 – Solutions

This README provides a summary and explanation of my solutions to the three problems in **Problem Set 2** of Harvard's CS50 course: **Readability**, **Caesar**, and **Substitution**. Each program was written in C and demonstrates concepts such as loops, strings, encryption, and command-line argument parsing.

---

## 📝 Problem 1: Readability

### 🔍 Description
This program determines the reading level of a user-inputted text using the **Coleman-Liau index**, which estimates the U.S. grade level necessary to comprehend the input.

### 📌 Key Concepts
- Loops and conditionals
- Counting characters, words, and sentences
- Applying the Coleman-Liau formula:
index = 0.0588 * L - 0.296 * S - 15.8
where `L` is the average number of letters per 100 words, and `S` is the average number of sentences per 100 words.

### 💡 Example
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3

---

## 🔐 Problem 2: Caesar Cipher

### 🔍 Description
This program encrypts a given plaintext using the **Caesar cipher**, which shifts each letter by a fixed number of positions in the alphabet. The key (number of positions) is passed as a command-line argument.

### 📌 Key Concepts
- Command-line argument parsing
- Validating numeric input
- Preserving character case
- Using modular arithmetic to wrap around the alphabet

### 💡 Example
$ ./caesar 1
plaintext: HELLO
### 🔒 Notes
- Non-alphabetic characters remain unchanged.
- Key must be a non-negative integer.

---

## 🔑 Problem 3: Substitution Cipher

### 🔍 Description
This program encrypts plaintext using a **substitution cipher**, where each letter is replaced by a corresponding letter from a given key (also passed via command-line). The key must be a 26-character string containing each letter of the alphabet exactly once.

### 📌 Key Concepts
- Argument validation (alphabet-only, length = 26, no duplicates)
- Case preservation
- Index mapping from plaintext to cipher key

### 💡 Example
$ ./substitution QWERTYUIOPASDFGHJKLZXCVBNM
plaintext: Hello, World!
ciphertext: Itssg, Vgksr!

---

## 🛠 Compilation

To compile each program using `make`:
make readability
make caesar
make substitution

Or manually using `clang`:
make readability
make caesar
make substitution

Or manually using `clang`:
clang -o readability readability.c
clang -o caesar caesar.c -lm
clang -o substitution substitution.c

---

## 📁 Files Included

- `readability.c` – Coleman-Liau index implementation
- `caesar.c` – Caesar cipher encryption
- `substitution.c` – Substitution cipher encryption

---

## ✅ What I Learned

- How to handle and validate command-line arguments
- Encrypting strings and characters in C
- Using loops, conditions, and ASCII value manipulations
- Implementing real-world encryption methods like Caesar and Substitution ciphers
- Understanding text analysis using readability formulas

---

## 💯 Status

All three programs were compiled and tested successfully. They meet all specifications provided in CS50’s Problem Set 2 and pass the `check50` automated tests.

---

ciphertext: IFMMP
