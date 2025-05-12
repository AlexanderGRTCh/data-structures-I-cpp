# linked-list-char-count-object

This project implements a C++ class `assign_obj` that manages a linked list of character–count pairs. Each object supports insertion, merging, compaction, and formatted output. It is designed to demonstrate deep copy, dynamic memory management, and operator overloading using raw pointers in a manually managed singly linked list.

## Overview

The `assign_obj` class internally uses a `node` struct to store characters and their counts. Nodes are dynamically created and manipulated through member functions and overloaded operators.

### Required Features

- Implement the class using a **linked list** (not arrays or STL vectors for storage).
- Must include:
  - A destructor that prints `DELETE`
  - A copy constructor that prints `COPY`
  - An assignment operator that prints `ASSIGNMENT`
- Must not hardcode any values.
- Must be compiled with the flag: `-fno-elide-constructors`

## Key Methods and Operators

- `assign_obj()`: Default constructor.
- `assign_obj(string input)`: Constructs the object from a string, converting characters to uppercase.
- `compact()`: Aggregates duplicate characters and sorts the list alphabetically.
- `f_add(char c)`: Adds a character to the front of the list.
- `e_add(char c)`: Adds a character to the end of the list.
- `operator+`: Merges two objects and compacts the result.
- `operator=`: Performs deep assignment, prints `ASSIGNMENT`.
- Copy constructor: Creates a deep copy of another object, prints `COPY`.
- Destructor: Deletes all nodes, prints `DELETE`.
- `operator<<`: Outputs the list in `[ A:1 B:2 ... ]` format.

## Program Flow

The provided driver performs the following steps:
1. Creates two assign_obj instances from strings.
2. Prints and compacts the first.
3. Copies it using the copy constructor.
4. Merges with the second object using `+` and assigns it back (assignment operator).
5. Adds characters using `f_add` and `e_add`.
6. Compacts and prints the final object.

## Files

- `assign_obj.h`: Class definition and method implementations using a linked list.
- `assign_driver.cpp`: Driver file to test class functionality.

## How to Compile & Run

```bash
g++ -fno-elide-constructors assign_driver.cpp -o run_assign
./run_assign
```

## Notes

- All data is stored as uppercase characters.
- Memory is managed manually using `new` and `delete`.
- No STL algorithms or containers are used for core storage.
- All required outputs (COPY, ASSIGNMENT, DELETE) appear when expected.
- The structure is tested to match assignment output specs without hardcoded behavior.
