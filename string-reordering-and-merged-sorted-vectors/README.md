# string-reordering-and-merged-sorted-vectors

This project includes two separate C++ programs. The first generates a random string of uppercase and lowercase letters and reorders it so that all lowercase letters appear before the uppercase ones. The second generates two random integer vectors (one in ascending order, one in descending order), merges them, and sorts the combined result using recursive merge sort.

## Program 1 – Reorder Mixed Case String

Generates a 16-character string composed of random upper- and lowercase letters. It then rearranges the string so that all lowercase letters come first, followed by all uppercase letters.

### Functions
- `genStr(string &s)`: Builds the initial random string using ASCII ranges.
- `lowerToUpper(string &s)`: Separates lowercase and uppercase characters and recombines them.

### Time Complexity
O(n), where n = 16. Both generation and reordering use simple linear scans.

## Program 2 – Merge and Sort Two Integer Vectors

Generates:
- One vector of 8 integers in ascending order.
- One vector of 8 integers in descending order.

These are merged into a single vector and then sorted using recursive merge sort.

### Functions
- `genAscV(vector<int>& a)`: Builds the ascending vector.
- `genDecV(vector<int>& d)`: Builds the descending vector.
- `merge(...)`: Merges two sorted vectors.
- `ms(...)`: Recursive merge sort function.

### Time Complexity
- Generation: O(n)
- Merge sort: O(n log n)

## Design Justification (from Justifications.txt)

Program 1:
- Used a for loop instead of recursion to avoid function call overhead.
- Both string generation and reordering are linear in time.

Program 2:
- Used merge sort due to its efficient O(n log n) average time.
- The merge function is reused to first combine vectors, then recursively sort the result.

## Files

- `Driver1.cpp`: Program 1 – string reordering.
- `Assignment4Two.cpp`: Program 2 – vector generation, merge, and sorting.
- `Justifications.txt`: Design explanation and time complexity analysis.
- `Assignment4.pdf`: Assignment instructions.

## How to Compile & Run

### Program 1 – String Reordering
```bash
g++ Driver1.cpp -o string_reorder
./string_reorder

### Program 2 – String Reordering
g++ Assignment4Two.cpp -o vector_merge_sort
./vector_merge_sort

Notes
    Both programs seed randomness using srand(time(0)).
    Recursion was intentionally avoided in Program 1 to maintain constant stack overhead.
    Merge sort in Program 2 was implemented recursively for efficiency and to match the assignment’s sorting requirements.
    No STL sort or algorithm functions were used.