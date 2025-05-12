# recursive-coin-flip-distribution

This project generates all possible outcomes for flipping a given number of coins and counts how many permutations result in each unique combination of heads and tails. The implementation is fully recursive and does not use any loops, per assignment constraints.

## Features

- Accepts user input for the number of coins.
- Recursively generates all head/tail combinations.
- Tracks how many outcomes result in 0H, 1H, ..., nH.
- Outputs each combination count as "xH yT : count".

## Files

- Driver.cpp – Main program and recursive logic.
- helper.txt – Sample permutations and counts used for validation.

## Program Behavior

1. Prompts user: "How many coins do you wish to flip?"
2. Recursively generates all 2ⁿ outcomes of coin flips.
3. For each permutation, counts how many heads.
4. Updates a result vector based on head count.
5. Prints total permutations per head–tail combination.

## Sample Input

How many coins do you wish to flip: 4

## Sample Output

0H 4T : 1  
1H 3T : 4  
2H 2T : 6  
3H 1T : 4  
4H 0T : 1

## How to Compile & Run

```bash
g++ Driver.cpp -o coin_flip
./coin_flip
