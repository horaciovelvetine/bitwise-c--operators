#include "bitwise_utils.h"
#include <iostream>
#include <string>
#include <limits>

void printMenu()
{
  std::cout << "\n<== Bitwise Operators Learning Tool ==>" << std::endl;
  std::cout << "0. Exit" << std::endl;
  std::cout << "1. Bitwise AND (&)" << std::endl;
  std::cout << "2. Bitwise OR (|)" << std::endl;
  std::cout << "3. Bitwise XOR (^)" << std::endl;
  std::cout << "4. Bitwise NOT (~)" << std::endl;
  std::cout << "5. Left Shift (<<)" << std::endl;
  std::cout << "6. Right Shift (>>)" << std::endl;
  std::cout << "7. Count Set Bits" << std::endl;
  std::cout << "8. Check if Bit is Set" << std::endl;
  std::cout << "9. Set Bit" << std::endl;
  std::cout << "10. Clear Bit" << std::endl;
  std::cout << "11. Toggle Bit" << std::endl;
  std::cout << "12. Run Demo Examples" << std::endl;
  std::cout << "13. Print Base Table" << std::endl;
  std::cout << "Enter your choice: ";
}

void runDemoExamples()
{
  std::cout << "\n=== Demo Examples ===" << std::endl;

  // Example 1: Basic AND operation
  uint32_t a = 0b10101010;
  uint32_t b = 0b11001100;
  uint32_t result = bitwise::bitwiseAnd(a, b);
  bitwise::displayBitwiseOperation(a, b, "AND", result);

  // Example 2: Basic OR operation
  a = 0b10101010;
  b = 0b11001100;
  result = bitwise::bitwiseOr(a, b);
  bitwise::displayBitwiseOperation(a, b, "OR", result);

  // Example 3: XOR operation
  a = 0b10101010;
  b = 0b11001100;
  result = bitwise::bitwiseXor(a, b);
  bitwise::displayBitwiseOperation(a, b, "XOR", result);

  // Example 4: NOT operation
  a = 0b10101010;
  result = bitwise::bitwiseNot(a);
  bitwise::displayBitwiseNotOperation(a, result);

  // Example 5: Left shift
  a = 0b00000001;
  int shift = 3;
  result = bitwise::leftShift(a, shift);
  bitwise::displayShiftOperation(a, shift, result, "LEFT");

  // Example 6: Right shift
  a = 0b10000000;
  shift = 2;
  result = bitwise::rightShift(a, shift);
  bitwise::displayShiftOperation(a, shift, result, "RIGHT");

  // Example 7: Practical examples
  std::cout << "\n=== Practical Examples ===" << std::endl;

  // Check if number is even/odd
  uint32_t num = 42;
  std::cout << "Number: " << num << " (" << bitwise::toBinaryString(num, 8) << ")" << std::endl;
  std::cout << "Is even: " << ((num & 1) == 0 ? "Yes" : "No") << std::endl;

  // Check if number is power of 2
  num = 16;
  std::cout << "Number: " << num << " (" << bitwise::toBinaryString(num, 8) << ")" << std::endl;
  std::cout << "Is power of 2: " << ((num & (num - 1)) == 0 ? "Yes" : "No") << std::endl;

  // Count set bits
  num = 0b10101010;
  std::cout << "Number: " << num << " (" << bitwise::toBinaryString(num, 8) << ")" << std::endl;
  std::cout << "Set bits count: " << bitwise::countSetBits(num) << std::endl;
}

uint32_t getInput(const std::string &prompt)
{
  uint32_t value;
  while (true)
  {
    std::cout << prompt;
    if (std::cin >> value)
    {
      break;
    }
    else
    {
      std::cout << "Invalid input. Please enter a valid number." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  return value;
}

int getBitPosition()
{
  int position;
  while (true)
  {
    std::cout << "Enter bit position (0-31): ";
    if (std::cin >> position && position >= 0 && position <= 31)
    {
      break;
    }
    else
    {
      std::cout << "Invalid input. Please enter a number between 0 and 31." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  return position;
}

int main()
{
  std::cout << "\n"
            << " <== Welcome to the Bitwise Operators Learning Tool ==>" << std::endl;
  std::cout << "This tool helps understand and visualize bitwise operations in C++." << std::endl;

  int choice;
  while (true)
  {
    printMenu();
    if (!(std::cin >> choice))
    {
      std::cout << "Invalid input. Please enter a number." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    switch (choice)
    {
    case 0:
      std::cout << "Goodbye!" << std::endl;
      return 0;

    case 1:
    { // AND
      uint32_t a = getInput("Enter first number: ");
      uint32_t b = getInput("Enter second number: ");
      uint32_t result = bitwise::bitwiseAnd(a, b);
      bitwise::displayBitwiseOperation(a, b, "AND", result);
      break;
    }

    case 2:
    { // OR
      uint32_t a = getInput("Enter first number: ");
      uint32_t b = getInput("Enter second number: ");
      uint32_t result = bitwise::bitwiseOr(a, b);
      bitwise::displayBitwiseOperation(a, b, "OR", result);
      break;
    }

    case 3:
    { // XOR
      uint32_t a = getInput("Enter first number: ");
      uint32_t b = getInput("Enter second number: ");
      uint32_t result = bitwise::bitwiseXor(a, b);
      bitwise::displayBitwiseOperation(a, b, "XOR", result);
      break;
    }

    case 4:
    { // NOT
      uint32_t a = getInput("Enter number: ");
      uint32_t result = bitwise::bitwiseNot(a);
      bitwise::displayBitwiseNotOperation(a, result);
      break;
    }

    case 5:
    { // Left Shift
      uint32_t a = getInput("Enter number: ");
      int shift = getInput("Enter shift amount: ");
      uint32_t result = bitwise::leftShift(a, shift);
      bitwise::displayShiftOperation(a, shift, result, "LEFT");
      break;
    }

    case 6:
    { // Right Shift
      uint32_t a = getInput("Enter number: ");
      int shift = getInput("Enter shift amount: ");
      uint32_t result = bitwise::rightShift(a, shift);
      bitwise::displayShiftOperation(a, shift, result, "RIGHT");
      break;
    }

    case 7:
    { // Count Set Bits
      uint32_t a = getInput("Enter number: ");
      int count = bitwise::countSetBits(a);
      std::cout << "\nNumber: " << a << " (" << bitwise::toBinaryString(a) << ")" << std::endl;
      std::cout << "Set bits count: " << count << std::endl;
      break;
    }

    case 8:
    { // Check if Bit is Set
      uint32_t a = getInput("Enter number: ");
      int position = getBitPosition();
      bool isSet = bitwise::isBitSet(a, position);
      std::cout << "\nNumber: " << a << " (" << bitwise::toBinaryString(a) << ")" << std::endl;
      std::cout << "Bit at position " << position << " is " << (isSet ? "SET" : "CLEAR") << std::endl;
      break;
    }

    case 9:
    { // Set Bit
      uint32_t a = getInput("Enter number: ");
      int position = getBitPosition();
      uint32_t result = bitwise::setBit(a, position);
      std::cout << "\nOriginal: " << a << " (" << bitwise::toBinaryString(a) << ")" << std::endl;
      std::cout << "After setting bit " << position << ": " << result << " (" << bitwise::toBinaryString(result) << ")" << std::endl;
      break;
    }

    case 10:
    { // Clear Bit
      uint32_t a = getInput("Enter number: ");
      int position = getBitPosition();
      uint32_t result = bitwise::clearBit(a, position);
      std::cout << "\nOriginal: " << a << " (" << bitwise::toBinaryString(a) << ")" << std::endl;
      std::cout << "After clearing bit " << position << ": " << result << " (" << bitwise::toBinaryString(result) << ")" << std::endl;
      break;
    }

    case 11:
    { // Toggle Bit
      uint32_t a = getInput("Enter number: ");
      int position = getBitPosition();
      uint32_t result = bitwise::toggleBit(a, position);
      std::cout << "\nOriginal: " << a << " (" << bitwise::toBinaryString(a) << ")" << std::endl;
      std::cout << "After toggling bit " << position << ": " << result << " (" << bitwise::toBinaryString(result) << ")" << std::endl;
      break;
    }

    case 12: // Demo Examples
      runDemoExamples();
      break;

    case 13:
    { // Print out a binary table
      int table_length = getInput("Enter desired table length: ");
      int basis = getInput("Enter the basis for the table (number of valid selections per bit): ");
      bitwise::displayBaseTable(table_length, basis);
      break;
    }

    default:
      std::cout << "Invalid choice. Please try again." << std::endl;
      break;
    }

    std::cout << "\nPress Enter to continue...";

    // Clear any remaining characters in the input buffer up to a newline
    // std::numeric_limits<std::streamsize>::max() specifies the maximum number of characters to ignore
    // '\n' tells it to stop when it finds a newline character
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
  }

  return 0;
}