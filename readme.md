# Arbitrary Precision Calculator (APC)
![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)
![Status](https://img.shields.io/badge/status-completed-brightgreen?style=flat-square)

## Overview
An Arbitrary Precision Calculator implemented in C that performs arithmetic on integers of unlimited length, bypassing built-in data type limits.
Numbers are represented internally using a **doubly linked list**, enabling digit-by-digit arithmetic similar to manual calculation.


## Project Structure
```
.
├── include/
│   └── apc.h              # Header file
├── src/
│   ├── addition.c         # Addition implementation
│   ├── division.c         # Division implementation
│   ├── list.c             # Linked list operations
│   ├── main.c             # Entry point
│   ├── multiplication.c   # Multiplication implementation
│   ├── result.c           # Result utilities
│   └── subtraction.c      # Subtraction implementation
└── tests/
    ├── printing.c         # Test utilities
    └── test.sh            # Test script
```

## Build & Run
```bash
make              # Compile
make test         # Run tests
make clean        # Clean build artifacts
```

## Usage
```bash
./a.out <operand_1> <operator> <operand_2>
```

**Examples:**
```bash
./a.out 100 + 200                    # 300
./a.out 500 - 300                    # 200
./a.out -100 + 50                    # -50
./a.out 25 x 4                       # 100
./a.out 100 / -1                     # -100
./a.out 123456789 x 987654321        # Large numbers
```

## Author
Arjun Vasavan

## License
[MIT License](./LICENSE) © 2025 Arjun Vasavan
