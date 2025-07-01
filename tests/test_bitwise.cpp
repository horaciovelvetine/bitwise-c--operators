#include "../include/bitwise_utils.h"
#include <iostream>
#include <cassert>
#include <string>

void testBinaryString()
{
  std::cout << "Testing toBinaryString..." << std::endl;

  assert(bitwise::toBinaryString(0, 8) == "0000 0000");
  assert(bitwise::toBinaryString(255, 8) == "1111 1111");
  assert(bitwise::toBinaryString(170, 8) == "1010 1010");
  assert(bitwise::toBinaryString(85, 8) == "0101 0101");

  std::cout << "✓ toBinaryString tests passed" << std::endl;
}

void testHexString()
{
  std::cout << "Testing toHexString..." << std::endl;

  assert(bitwise::toHexString(0) == "0x0");
  assert(bitwise::toHexString(255) == "0xFF");
  assert(bitwise::toHexString(170) == "0xAA");
  assert(bitwise::toHexString(85) == "0x55");

  std::cout << "✓ toHexString tests passed" << std::endl;
}

void testBitwiseOperations()
{
  std::cout << "Testing bitwise operations..." << std::endl;

  // Test AND
  assert(bitwise::bitwiseAnd(0b1010, 0b1100) == 0b1000);
  assert(bitwise::bitwiseAnd(0b1111, 0b0000) == 0b0000);
  assert(bitwise::bitwiseAnd(0b1111, 0b1111) == 0b1111);

  // Test OR
  assert(bitwise::bitwiseOr(0b1010, 0b1100) == 0b1110);
  assert(bitwise::bitwiseOr(0b0000, 0b1111) == 0b1111);
  assert(bitwise::bitwiseOr(0b1010, 0b0101) == 0b1111);

  // Test XOR
  assert(bitwise::bitwiseXor(0b1010, 0b1100) == 0b0110);
  assert(bitwise::bitwiseXor(0b1111, 0b1111) == 0b0000);
  assert(bitwise::bitwiseXor(0b1010, 0b0101) == 0b1111);

  // Test NOT
  assert(bitwise::bitwiseNot(0b0000) == 0xFFFFFFFF);
  assert(bitwise::bitwiseNot(0b1111) == 0xFFFFFFF0);

  std::cout << "✓ Bitwise operations tests passed" << std::endl;
}

void testShiftOperations()
{
  std::cout << "Testing shift operations..." << std::endl;

  // Test left shift
  assert(bitwise::leftShift(0b0001, 1) == 0b0010);
  assert(bitwise::leftShift(0b0001, 3) == 0b1000);
  assert(bitwise::leftShift(0b1010, 2) == 0b101000);

  // Test right shift
  assert(bitwise::rightShift(0b1000, 1) == 0b0100);
  assert(bitwise::rightShift(0b1000, 3) == 0b0001);
  assert(bitwise::rightShift(0b101000, 2) == 0b1010);

  std::cout << "✓ Shift operations tests passed" << std::endl;
}

void testBitManipulation()
{
  std::cout << "Testing bit manipulation..." << std::endl;

  uint32_t value = 0b0000;

  // Test set bit
  value = bitwise::setBit(value, 0);
  assert(value == 0b0001);
  value = bitwise::setBit(value, 2);
  assert(value == 0b0101);

  // Test clear bit
  value = bitwise::clearBit(value, 0);
  assert(value == 0b0100);

  // Test toggle bit
  value = bitwise::toggleBit(value, 1);
  assert(value == 0b0110);
  value = bitwise::toggleBit(value, 1);
  assert(value == 0b0100);

  // Test is bit set
  assert(bitwise::isBitSet(value, 2) == true);
  assert(bitwise::isBitSet(value, 0) == false);

  std::cout << "✓ Bit manipulation tests passed" << std::endl;
}

void testCountSetBits()
{
  std::cout << "Testing countSetBits..." << std::endl;

  assert(bitwise::countSetBits(0) == 0);
  assert(bitwise::countSetBits(0b1111) == 4);
  assert(bitwise::countSetBits(0b1010) == 2);
  assert(bitwise::countSetBits(0b0101) == 2);
  assert(bitwise::countSetBits(0xFFFFFFFF) == 32);

  std::cout << "✓ countSetBits tests passed" << std::endl;
}

void runAllTests()
{
  std::cout << "Running all tests..." << std::endl;
  std::cout << "====================" << std::endl;

  testBinaryString();
  testHexString();
  testBitwiseOperations();
  testShiftOperations();
  testBitManipulation();
  testCountSetBits();

  std::cout << "====================" << std::endl;
  std::cout << "All tests passed! ✓" << std::endl;
}

int main()
{
  runAllTests();
  return 0;
}