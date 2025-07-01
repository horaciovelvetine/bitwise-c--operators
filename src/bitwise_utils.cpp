#include "bitwise_utils.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

namespace bitwise
{
  // default value of 32 bits...
  std::string toBinaryString(uint32_t value, int bits)
  {
    std::string result;
    for (int i = bits - 1; i >= 0; --i)
    {
      result += ((value >> i) & 1) ? '1' : '0';
      if (i % 4 == 0 && i != 0)
      {
        result += ' '; // Add space every 4 bits for readability
      }
    }
    return result;
  }

  std::string toHexString(uint32_t value)
  {
    std::stringstream ss;
    ss << "0x" << std::hex << std::uppercase << value;
    return ss.str();
  }

  uint32_t bitwiseAnd(uint32_t a, uint32_t b)
  {
    return a & b;
  }

  uint32_t bitwiseOr(uint32_t a, uint32_t b)
  {
    return a | b;
  }

  uint32_t bitwiseXor(uint32_t a, uint32_t b)
  {
    return a ^ b;
  }

  uint32_t bitwiseNot(uint32_t a)
  {
    return ~a;
  }

  uint32_t leftShift(uint32_t a, int shift)
  {
    return a << shift;
  }

  uint32_t rightShift(uint32_t a, int shift)
  {
    return a >> shift;
  }

  long long power(int base, int exponent)
  {
    long long result = 1;
    for (int itr = 0; itr < exponent; itr++)
    {
      result *= base;
    }
    return result;
  }

  void displayBaseTable(int table_length, int basis)
  {
    std::string values_row;
    std::string powers_row;
    int longest_value;

    for (int i = table_length; i >= 0; i--)
    {
      // Value row build
      long long value = power(basis, i);
      std::string value_str = std::to_string(value);
      if (i == table_length)
      {
        longest_value = value_str.length();
      }

      if (value_str.length() < longest_value)
      {
        int spacesToAdd = longest_value - value_str.length();
        value_str = std::string(spacesToAdd, ' ') + value_str;
      }
      values_row += (value_str + "|");

      // Power row build
      std::string exponent_str = std::to_string(i);
      std::string basis_str = (std::to_string(basis) + "^");
      int powers_whitespace = longest_value - (exponent_str.length() + basis_str.length()); // {basis}^(i)
      powers_row += (std::string(powers_whitespace, ' ') + basis_str + exponent_str) + "|";
    }
    values_row += "\n";
    std::cout << "\n<== Base" << basis << " Table ==> \n";
    std::cout << values_row << powers_row << std::endl;
  }

  void displayBitwiseOperation(uint32_t a, uint32_t b, const std::string &operation, uint32_t result)
  {
    std::cout << "\n<== Bitwise " << operation << " Operation ==>" << std::endl;
    std::cout << "Decimal: " << a << " " << operation << " " << b << " = " << result << std::endl;
    std::cout << "Hex:     " << toHexString(a) << " " << operation << " " << toHexString(b) << " = " << toHexString(result) << std::endl;
    std::cout << std::endl;

    std::string binA = toBinaryString(a);
    std::string binB = toBinaryString(b);
    std::string binResult = toBinaryString(result);

    // Show bit-by-bit comparison
    std::cout << "Bit-by-bit comparison:" << std::endl;
    for (int i = 31; i >= 0; --i)
    {
      if (i % 4 == 3)
        std::cout << " ";
      std::cout << ((a >> i) & 1);
    }
    std::cout << " (A)" << std::endl;

    for (int i = 31; i >= 0; --i)
    {
      if (i % 4 == 3)
        std::cout << " ";
      std::cout << ((b >> i) & 1);
    }
    std::cout << " (B)" << std::endl;

    std::cout << std::string(44, '-') << std::endl;

    for (int i = 31; i >= 0; --i)
    {
      if (i % 4 == 3)
        std::cout << " ";
      std::cout << ((result >> i) & 1);
    }
    std::cout << " (Result)" << std::endl;
  }

  void displayBitwiseNotOperation(uint32_t a, uint32_t result)
  {
    std::cout << "\n<== Bitwise NOT Operation ==>" << std::endl;
    std::cout << "Decimal: ~" << a << " = " << result << std::endl;
    std::cout << "Hex:     ~" << toHexString(a) << " = " << toHexString(result) << std::endl;
    std::cout << std::endl;

    std::string binA = toBinaryString(a);
    std::string binResult = toBinaryString(result);

    // Show bit-by-bit comparison
    std::cout << "Bit-by-bit comparison:" << std::endl;
    for (int i = 31; i >= 0; --i)
    {
      if (i % 4 == 3)
        std::cout << " ";
      std::cout << ((a >> i) & 1);
    }
    std::cout << " (A)" << std::endl;

    std::cout << std::string(44, '-') << std::endl;

    for (int i = 31; i >= 0; --i)
    {
      if (i % 4 == 3)
        std::cout << " ";
      std::cout << ((result >> i) & 1);
    }
    std::cout << " (~A)" << std::endl;
  }

  void displayShiftOperation(uint32_t a, int shift, uint32_t result, const std::string &direction)
  {
    std::cout << "\n<== " << direction << " Shift Operation ==>" << std::endl;
    std::cout << "Decimal: " << a << " " << (direction == "LEFT" ? "<<" : ">>") << " " << shift << " = " << result << std::endl;
    std::cout << "Hex:     " << toHexString(a) << " " << (direction == "LEFT" ? "<<" : ">>") << " " << shift << " = " << toHexString(result) << std::endl;
    std::cout << std::endl;

    std::string binA = toBinaryString(a);
    std::string binResult = toBinaryString(result);

    // Show shift visualization
    std::cout << "Shift visualization:" << std::endl;
    for (int i = 31; i >= 0; --i)
    {
      if (i % 4 == 3)
        std::cout << " ";
      std::cout << ((a >> i) & 1);
    }
    std::cout << " (Original)" << std::endl;

    if (direction == "LEFT")
    {
      std::cout << std::string(shift * 2, ' ') << "←- shifted left by " << shift << " positions" << std::endl;
    }
    else
    {
      std::cout << std::string(shift * 2, ' ') << "-→ shifted right by " << shift << " positions" << std::endl;
    }

    for (int i = 31; i >= 0; --i)
    {
      if (i % 4 == 3)
        std::cout << " ";
      std::cout << ((result >> i) & 1);
    }
    std::cout << " (Result)" << std::endl;
  }

  int countSetBits(uint32_t value)
  {
    int count = 0;
    while (value)
    {
      count += value & 1;
      value >>= 1;
    }
    return count;
  }

  bool isBitSet(uint32_t value, int bitPosition)
  {
    return (value >> bitPosition) & 1;
  }

  uint32_t setBit(uint32_t value, int bitPosition)
  {
    return value | (1U << bitPosition);
  }

  uint32_t clearBit(uint32_t value, int bitPosition)
  {
    return value & ~(1U << bitPosition);
  }

  uint32_t toggleBit(uint32_t value, int bitPosition)
  {
    return value ^ (1U << bitPosition);
  }

} // namespace bitwise