# longest-ascending-frequency-sequence

This project reads character–count pairs from a file and builds two parallel vectors: one for characters and one for their total counts. It identifies the longest ascending subsequence in the count vector and prints the corresponding characters.

## Features

- Aggregates duplicate character entries.
- Builds unique vectors for character–count mapping.
- Detects the longest strictly ascending sequence in the count vector.
- Prints input data and the matching character subsequence.

## Files

- `Driver.cpp` – Main logic and all function definitions.
- `test1.txt` to `test5.txt` – Sample input files for testing.

## Implemented Functions

- `check()` – Adds or updates character–count pairs in the vectors.
- `get_vector()` – Parses the input file into vectors.
- `print_input()` – Outputs each character and its total count.
- `longest_asc_sub()` – Finds the longest ascending segment in the count vector.
- `print_subset()` – Prints characters corresponding to that segment.

## Example Input (`test1.txt`)
