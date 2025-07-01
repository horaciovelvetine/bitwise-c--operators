# Bitwise C++ Operators Learning Tool

A command-line tool to help visualize and develop an understanding of bitwise operators in C++.

## Supported Operations

1. **Bitwise AND (&)** - Logical AND on each bit
2. **Bitwise OR (|)** - Logical OR on each bit  
3. **Bitwise XOR (^)** - Logical XOR on each bit
4. **Bitwise NOT (~)** - Logical NOT (complement) on each bit
5. **Left Shift (<<)** - Shift bits to the left
6. **Right Shift (>>)** - Shift bits to the right
7. **Bit Counting** - Count the number of set bits
8. **Bit Manipulation** - Set, clear, toggle, and check individual bits

## Building the Project

### Prerequisites

- C++17 compatible compiler (GCC, Clang, or MSVC)
- CMake (version 3.10 or higher) - optional
- Make - optional

### Using CMake (Recommended)

```bash
mkdir build
cd build
cmake ..
make
```

### Using Make

```bash
make
```

### Manual Compilation

```bash
g++ -std=c++17 -Wall -Wextra -Iinclude -o bitwise_operators src/main.cpp src/bitwise_utils.cpp
```

## Running the Program

```bash
./bitwise_operators
```

### Use

The program provides an interactive menu where you can:

1. Choose an operation (1-13)
2. Enter input values
3. View detailed results with binary visualization
4. Run demo examples

### Example Output

```
=== Bitwise AND Operation ===
Decimal: 170 AND 204 = 136
Hex:     0xAA AND 0xCC = 0x88

Bit-by-bit comparison:
 0000 0000 0000 0000 0000 0000 1010 1010 (A)
 0000 0000 0000 0000 0000 0000 1100 1100 (B)
 ---------------------------------
 0000 0000 0000 0000 0000 0000 1000 1000 (Result)
```

## Testing

Run the test suite to verify all operations work correctly:

```bash
# Using Make
make test

# Manual compilation and testing
g++ -std=c++17 -Iinclude -o test_bitwise tests/test_bitwise.cpp src/bitwise_utils.cpp
./test_bitwise
```

## Project Structure

```
bitwise-c--operators/
├── CMakeLists.txt          # CMake build configuration
├── Makefile               # Make build configuration
├── README.md              # This file
├── include/
│   └── bitwise_utils.h    # Header file with function declarations
├── src/
│   ├── main.cpp           # Main application with interactive menu
│   └── bitwise_utils.cpp  # Implementation of bitwise operations
└── tests/
    └── test_bitwise.cpp   # Test suite
```

## API Reference

### Core Functions

- `toBinaryString(value, bits)` - Convert integer to binary string
- `toHexString(value)` - Convert integer to hexadecimal string
- `bitwiseAnd(a, b)` - Perform bitwise AND operation
- `bitwiseOr(a, b)` - Perform bitwise OR operation
- `bitwiseXor(a, b)` - Perform bitwise XOR operation
- `bitwiseNot(a)` - Perform bitwise NOT operation
- `leftShift(a, shift)` - Perform left shift operation
- `rightShift(a, shift)` - Perform right shift operation

### Utility Functions

- `power(base, exponent)` - Calculate an exponent
- `countSetBits(value)` - Count number of set bits
- `isBitSet(value, position)` - Check if specific bit is set
- `setBit(value, position)` - Set a specific bit
- `clearBit(value, position)` - Clear a specific bit
- `toggleBit(value, position)` - Toggle a specific bit

### Display Functions

- `displayBaseTable(table_length, basis)` - Outputs a table of any int based system of the desired length
- `displayBitwiseOperation(a, b, operation, result)` - Show detailed operation visualization
- `displayBitwiseNotOperation(a, result)` - Show NOT operation visualization
- `displayShiftOperation(a, shift, result, direction)` - Show shift operation visualization

## Practical Applications

This tool helps understand common bitwise techniques:

- **Even/Odd Detection**: `(n & 1) == 0`
- **Power of 2 Check**: `(n & (n - 1)) == 0`
- **Bit Counting**: Count set bits in a number
- **Flag Manipulation**: Set/clear/toggle individual flags
- **Bit Masks**: Extract specific bits from a value


## Educational Resources

For more information about bitwise operations:

- [C++ Bitwise Operators](https://en.cppreference.com/w/cpp/language/operator_arithmetic#Bitwise_operators)
- [Bit Manipulation](https://en.wikipedia.org/wiki/Bit_manipulation)
- [Bitwise Operations](https://en.wikipedia.org/wiki/Bitwise_operation)
- [W3 Schools](https://www.geeksforgeeks.org/cpp/cpp-bitwise-operators/)
- [CMake Tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html)

