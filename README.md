# data-structures-I-cpp

This repository contains a series of C++ projects demonstrating core data structure implementations, recursion, stack-based logic, and object-oriented programming techniques. These projects were developed as part of coursework focused on building foundational algorithmic and memory management skills using C++.

## Project Index

### 1. longest-ascending-frequency-sequence
Builds character–count vectors from input and finds the longest strictly increasing subsequence in the count vector. Emphasizes manual vector manipulation and subsequence logic.

### 2. recursive-coin-flip-distribution
Recursively generates all outcomes for flipping n coins and counts how many ways each head-count occurs. Fully recursive — no loops allowed.

### 3. recursive-positive-path-in-matrix
Uses recursive backtracking to find a continuous path through a 2D matrix from top-left to bottom-right where the path sum is greater than zero. Cells can be visited only once.

### 4. string-reordering-and-merged-sorted-vectors
Two small programs: one reorders a random mixed-case string (lowercase before uppercase), and the other merges and recursively sorts two vectors (one ascending, one descending).

### 5. custom-object-char-count-vector
Implements an `assign_obj` class using STL vectors to track character–count pairs. Supports merging, compaction, and formatted output using overloaded operators.

### 6. dynamic-array-char-count-object
Reimplements `assign_obj` using raw dynamic arrays instead of vectors. Includes copy constructor, assignment operator, and destructor with tracking output (COPY, ASSIGNMENT, DELETE).

### 7. linked-list-char-count-object
Final version of `assign_obj`, this time using a custom singly linked list for storage. Demonstrates deep copy and memory safety using manual pointer logic.

### 8. stack-based-positive-pathfinder
Attempts to find a valid path through a 2D matrix using a custom stack class and iterative simulation of recursion. Uses flags, directional control, and backtracking.

### 9. rpn-calculator-using-custom-stack
Implements a reverse Polish notation calculator using a templated linked-list stack. Accepts single-digit positive integers and four basic operators. Validates input and returns a floating-point result.

## How to Compile

Each project contains its own README with specific compile instructions. All projects are written in standard C++ and require no external libraries beyond the standard library.

## Notes

- This repo reflects progression from high-level STL logic to low-level memory and pointer management.
- Projects are ordered to highlight the increasing complexity and responsibility over dynamic structures.
