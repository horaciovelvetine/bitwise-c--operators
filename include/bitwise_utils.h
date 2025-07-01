#ifndef BITWISE_UTILS_H
#define BITWISE_UTILS_H

#include <cstdint>
#include <string>
#include <vector>

namespace bitwise
{

  /**
   * @brief Converts an integer to its binary string representation
   * @param value The integer value to convert
   * @param bits Number of bits to show (default: 32)
   * @return Binary string representation
   */
  std::string toBinaryString(uint32_t value, int bits = 32);

  /**
   * @brief Converts an integer to its hexadecimal string representation
   * @param value The integer value to convert
   * @return Hexadecimal string representation
   */
  std::string toHexString(uint32_t value);

  /**
   * @brief Performs bitwise AND operation and returns detailed result
   * @param a First operand
   * @param b Second operand
   * @return Result of a & b
   */
  uint32_t bitwiseAnd(uint32_t a, uint32_t b);

  /**
   * @brief Performs bitwise OR operation and returns detailed result
   * @param a First operand
   * @param b Second operand
   * @return Result of a | b
   */
  uint32_t bitwiseOr(uint32_t a, uint32_t b);

  /**
   * @brief Performs bitwise XOR operation and returns detailed result
   * @param a First operand
   * @param b Second operand
   * @return Result of a ^ b
   */
  uint32_t bitwiseXor(uint32_t a, uint32_t b);

  /**
   * @brief Performs bitwise NOT operation and returns detailed result
   * @param a Operand
   * @return Result of ~a
   */
  uint32_t bitwiseNot(uint32_t a);

  /**
   * @brief Performs left shift operation and returns detailed result
   * @param a Operand to shift
   * @param shift Number of positions to shift left
   * @return Result of a << shift
   */
  uint32_t leftShift(uint32_t a, int shift);

  /**
   * @brief Performs right shift operation and returns detailed result
   * @param a Operand to shift
   * @param shift Number of positions to shift right
   * @return Result of a >> shift
   */
  uint32_t rightShift(uint32_t a, int shift);

  /**
   * @brief calculate the value of the provided base and exponent pair
   * @return the result of the exponential calculation
   */
  long long power(int base, int exponent);

  /**
   * @brief Displays a basis table with the powers and values associated with the provided base (basis) system value of the provided table length
   * @param table_length the number of places to display in the table
   * @param basis the number base for the preferred system
   */
  void displayBaseTable(int table_length, int basis);

  /**
   * @brief Displays a detailed comparison of two values and their bitwise operation result
   * @param a First operand
   * @param b Second operand
   * @param operation Operation name (e.g., "AND", "OR", "XOR")
   * @param result Result of the operation
   */
  void displayBitwiseOperation(uint32_t a, uint32_t b, const std::string &operation, uint32_t result);

  /**
   * @brief Displays a detailed view of a single value and its bitwise NOT operation
   * @param a Operand
   * @param result Result of the NOT operation
   */
  void displayBitwiseNotOperation(uint32_t a, uint32_t result);

  /**
   * @brief Displays a detailed view of a shift operation
   * @param a Original value
   * @param shift Number of positions to shift
   * @param result Result of the shift operation
   * @param direction Direction of shift ("LEFT" or "RIGHT")
   */
  void displayShiftOperation(uint32_t a, int shift, uint32_t result, const std::string &direction);

  /**
   * @brief Counts the number of set bits (1s) in an integer
   * @param value The integer to count bits in
   * @return Number of set bits
   */
  int countSetBits(uint32_t value);

  /**
   * @brief Checks if a specific bit is set
   * @param value The integer to check
   * @param bitPosition Position of the bit to check (0-based)
   * @return true if the bit is set, false otherwise
   */
  bool isBitSet(uint32_t value, int bitPosition);

  /**
   * @brief Sets a specific bit in an integer
   * @param value The integer to modify
   * @param bitPosition Position of the bit to set (0-based)
   * @return Modified integer with the bit set
   */
  uint32_t setBit(uint32_t value, int bitPosition);

  /**
   * @brief Clears a specific bit in an integer
   * @param value The integer to modify
   * @param bitPosition Position of the bit to clear (0-based)
   * @return Modified integer with the bit cleared
   */
  uint32_t clearBit(uint32_t value, int bitPosition);

  /**
   * @brief Toggles a specific bit in an integer
   * @param value The integer to modify
   * @param bitPosition Position of the bit to toggle (0-based)
   * @return Modified integer with the bit toggled
   */
  uint32_t toggleBit(uint32_t value, int bitPosition);

} // namespace bitwise

#endif // BITWISE_UTILS_H