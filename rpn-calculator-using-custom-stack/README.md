# rpn-calculator-using-custom-stack

This project implements a Reverse Polish Notation (RPN) calculator using a manually implemented stack class in C++. The stack is built as a singly linked list and used to evaluate postfix mathematical expressions composed of single-digit positive integers and the operators +, -, *, and /.

## Overview

The calculator takes a single input string representing a postfix expression (e.g., "42+") and evaluates it using a custom stack. Each time an operator is encountered, two operands are popped from the stack, the operation is applied, and the result is pushed back onto the stack.

### Supported Features

- Handles `+`, `-`, `*`, `/` operators.
- Validates input for:
  - Insufficient operands
  - Division by zero
  - Leftover values in the stack after evaluation
- Accepts only single-digit positive integers in the expression.
- Final result supports floating-point numbers.

## Stack Class

The `stack3<T>` class supports the following:

- `push(T)`: Adds an element to the top of the stack.
- `pop()`: Removes and returns the top element.
- `peek()`: Returns the top element without removing it.
- `isEmpty()`: Returns true if the stack is empty.
- Implemented as a singly linked list using a private `node` struct.

## Files

- `Driver.cpp`: Main logic to read input and evaluate the expression.
- `stack.h`: Header-only definition and implementation of the templated stack class.

## How to Compile & Run

```bash
g++ Driver.cpp -o rpn_calc
./rpn_calc
```

Example input:
```
Enter an equation:
42+
Solution 6
```

## Notes

- The program exits early with a message if the expression is invalid (e.g., too few operands or leftover stack values).
- Division by zero is explicitly checked and handled.
- The calculator processes characters one by one and converts digits from ASCII using `i - '0'`.
