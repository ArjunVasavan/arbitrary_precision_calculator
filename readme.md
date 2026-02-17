# Arbitrary Precision Calculator (APC)

![C](https://img.shields.io/badge/language-C-blue?style=flat-square)
![Status](https://img.shields.io/badge/status-completed-brightgreen?style=flat-square)
![License](https://img.shields.io/badge/license-MIT-green?style=flat-square)

---

## Overview

An **Arbitrary Precision Calculator implemented in C** that performs arithmetic on integers of unlimited length, bypassing built-in data type limits.

Numbers are internally represented using a **doubly linked list**, enabling digit-by-digit arithmetic similar to manual calculation.

---

## Project Structure

```
.
├── include/
│   └── apc.h
├── src/
│   ├── main.c
│   ├── list.c
│   ├── addition.c
│   ├── subtraction.c
│   ├── multiplication.c
│   ├── division.c
│   └── result.c
├── tests/
│   ├── printing.c
│   └── test.sh
├── build/          # Generated object files
├── Makefile
└── README.md
```

---

## Build & Run

```bash
make        # Compile project
make test   # Run test script
make clean  # Remove build artifacts
```

---

## Usage

```bash
./apc <first_operand> <operator> <second_operand>
```

---

## Examples

```bash
./apc 100 + 200
./apc 500 - 300
./apc -100 + 50
./apc 25 x 4
./apc 100 / -1
./apc 123456789 x 987654321
```
---

## Author

Arjun Vasavan

---

## License

This project is licensed under the MIT License.

© 2025 Arjun Vasavan
