
# 🧠 CS50x 2024 - Problem Set 3

This folder contains my solutions for Problem Set 3 of CS50x 2025. The focus of this problem set is on implementing different voting systems using C. The three problems are:

- ✅ Plurality
- ✅ Runoff
- ✅ Tideman (Ranked Pairs)

---

## 🗳️ Plurality

### Description:
Implements the **plurality voting system**, where each voter votes for one candidate, and the candidate with the most votes wins. If there is a tie, all winners are printed.

### Concepts Used:
- Arrays
- Structs
- String comparison
- Looping and counting

### Compilation and Usage:
```bash
make plurality
./plurality Alice Bob Charlie
````

### Example:

```
Number of voters: 3
Vote: Alice
Vote: Bob
Vote: Alice
Alice
```

---

## 🗳️ Runoff

### Description:

Implements an **instant-runoff voting system**, where voters rank candidates by preference. The last-place candidate is eliminated in each round, and votes are redistributed until one candidate has a majority.

### Concepts Used:

* 2D arrays
* Structs
* Loops and conditional logic
* Elimination and recursive-style logic

### Compilation and Usage:

```bash
make runoff
./runoff Alice Bob Charlie
```

### Example:

```
Number of voters: 5
Rank 1: Alice
Rank 2: Charlie
Rank 3: Bob
...
Alice
```

---

## 🗳️ Tideman (Ranked Pairs)

### Description:

Implements the **Tideman voting system** (also known as Ranked Pairs), which uses pairwise comparisons between candidates, sorts them by strength of victory, and locks them in without creating cycles to determine the winner.

### Concepts Used:

* Pairwise preferences
* Sorting algorithm (like selection sort)
* Graph cycles and locking
* Depth-first search (DFS) to check for cycles

### Compilation and Usage:

```bash
make tideman
./tideman Alice Bob Charlie
```

### Example:

```
Number of voters: 5
Rank 1: Charlie
Rank 2: Alice
Rank 3: Bob
...
Charlie
```

---

## 🧠 Skills Gained

* Working with complex data structures in C
* Algorithmic thinking for election logic
* Graph-based cycle detection
* Multi-round vote counting and candidate elimination

---

## 📁 Files

* `plurality.c` – Plurality voting system
* `runoff.c` – Instant-runoff voting system
* `tideman.c` – Tideman ranked pairs voting system

---

## 📚 References

* CS50 2025 Lectures and Notes
* Problem Set 3 Specifications
* [https://cs50.harvard.edu/x/2024/psets/3/](https://cs50.harvard.edu/x/2024/psets/3/)
