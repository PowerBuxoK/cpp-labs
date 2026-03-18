#include "LongInt.h"
#include "task2.h"
#include "task3.h"
#include <iostream>

// TODO: separate to many files

int main(int argc, char const* argv[])
{
  std::cout << "1. Division with no division operator:\n-100 / (-25) is " << signed_division(-100, -25) << std::endl;
  std::cout << "-2147483648 / (80) is " << signed_division(std::numeric_limits<int>::min(), 80) << std::endl;

  LongInt number = 4123;
  std::cout << "2. Long arithmetic:\n(4123+444-123)*333" << ((number + 444 - 123) * 333) << std::endl;
  std::cout << "Factorial of 123 is " << fact(123) << std::endl;

  std::cout << "3. Try-throw-catch:" << std::endl;
  func1();

  return 0;
}
