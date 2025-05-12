# recursive-positive-path-in-matrix

This program reads a matrix of integers from a user-specified input file and searches for a continuous path from the top-left corner to the bottom-right corner with a total sum greater than zero. The path is found using recursive backtracking and can move up, down, left, or right without revisiting any cell.

## Features

- Loads matrix dimensions and values from a file.
- Stores the matrix as a vector of vectors (`std::vector<std::vector<int>>`).
- Recursively explores all valid paths from the top-left to the bottom-right cell.
- Ensures each path:
  - Only visits each cell once.
  - Has a total sum greater than zero.
- Outputs a visual map of the path using:
  - `V` for down
  - `^` for up
  - `>` for right
  - `<` for left
  - `X` where the path ends
  - `-` for all unused cells

## Files

- Driver.cpp – Main file with path-finding logic.
- Matrix.txt to Matrix4.txt – Sample matrix input files.

## Matrix File Format

Each file begins with two lines:
1. Number of rows
2. Number of columns  
Followed by space-separated rows of integers representing the matrix.

Example:
4  
5  
1 -10 1 -5 2  
2 3 -20 2 1  
-13 1 2 3 5  
1 1 5 -4 4  

## Sample Output (conceptual)

For a successful path:
V - - - -  
V > > > >  
- - - - >  
- - - - X  

## How to Compile & Run

g++ Driver.cpp -o path_finder  
./path_finder  

Follow the program prompt to enter the name of the matrix file (e.g., Matrix.txt).

## Notes

- The core path search is implemented recursively (no loops).
- Paths that fail to reach the bottom-right or do not exceed a zero-sum are ignored.
- Input validation and file safety should be considered when extending this solution.
