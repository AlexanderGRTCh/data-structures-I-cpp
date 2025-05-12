# custom-object-char-count-vector

This project implements a C++ class that stores and manipulates a vector of character–integer pairs. The class includes functionality to construct objects from strings, merge them, compact repeated characters into counts, and print the result in a specific format. All character data is automatically converted to uppercase. This project was built to pass the output expectations defined in a provided assignment driver and must not use hardcoded values.

## Overview

The `assign_obj` class encapsulates a vector of structs, each holding a character and an integer count. It supports the following operations:

- Construct from a string.
- Print formatted output.
- Add characters to front or end.
- Merge two objects with automatic compaction.
- Compact the object (aggregate repeated characters and sort alphabetically).

## Key Functions and Operators

- `assign_obj()`: Default constructor.
- `assign_obj(string input)`: Builds an object from a string, converting all characters to uppercase and setting initial count to 1 for each.
- `compact()`: Merges identical characters and reorders the vector alphabetically.
- `f_add(char c)`: Adds a new character to the front of the vector.
- `e_add(char c)`: Adds a new character to the end of the vector.
- `operator+`: Adds two `assign_obj` instances, compacts both first, merges their contents, then compacts again.
- `operator<<`: Prints an object in the format `[ A:1 B:2 C:1 ... ]`.

## Program Flow

The program in `Driver.cpp` performs the following:

1. Constructs two objects from given strings.
2. Prints the raw character data.
3. Compacts and prints one of them.
4. Adds the two objects and prints the result.
5. Inserts more characters at the front and back.
6. Compacts the final result and prints it.

No STL algorithms are used; operations like sorting and merging are implemented using manual logic.

## Example Output (Simplified)

```
[ D:1 S:1 D:1 F:1 ... ]  
[ B:1 D:4 F:4 H:1 ... ]  
[ A:1 C:2 D:2 E:1 ... ]  
[ A:1 B:1 C:2 D:6 ... Z:3 ]
```

## Files

- `assign_obj.h`: Header file with full implementation of the `assign_obj` class.
- `Driver.cpp`: Main program demonstrating class usage and required output.


## How to Compile & Run

```bash
g++ Driver.cpp -o char_counter
./char_counter
```

## Notes

- All characters are automatically converted to uppercase during input or addition.
- `compact()` uses a 26-element integer array to count characters efficiently, avoiding nested loops.
- Insertion functions (`f_add`, `e_add`) work in O(1) amortized time.
- The merge operation and `+` operator rely on compacted objects to ensure correctness and minimize redundant counting.
- Output formatting and ordering are designed to meet exact assignment requirements, not general-purpose behavior.
