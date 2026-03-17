#include "LongInt.h"
#include <iostream>

int signed_division(int a, int b)
{
  int result;
  asm(
      "movl %1, %%eax\n\t"   // Move dividend into EAX
      "cdq\n\t"              // Sign-extend EAX into EDX (EDX:EAX = dividend)
      "idivl %2\n\t"         // Signed divide by divisor
      "movl %%eax, %0\n\t"   // Move result from EAX to output variable
      : "=r"(result)         // Output operands
      : "r"(a), "r"(b)       // Input operands
      : "%eax", "%edx", "cc" // Clobbered registers and condition codes (cuz of overflow)
  );
  return result;
}

void func5()
{
  double h = 1.0;
  throw(h);
}

void func4()
{
  std::cout << "func4" << std::endl;
  func5();
  std::cout << "func4 end" << std::endl;
}

void func3()
{
  std::cout << "func3" << std::endl;
  func4();
  std::cout << "func3 end" << std::endl;
}

void func2()
{
  std::cout << "func2" << std::endl;
  func3();
  std::cout << "func2 end" << std::endl;
}

void func1()
{
  std::cout << "func1" << std::endl;
  try
  {
    func2();
  }
  catch(const double& e)
  {
    std::cerr << "Excepted double: " << e << '\n';
  }
  std::cout << "func1 end" << std::endl;
}

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
