#include "LongInt.h"
#include <cinttypes>
#include <cstdint>
#include <iostream>

void PrintHelp(char* argv[])
{
  std::cout << "Program usage: \n"
            << argv[0] << R"( [task]

Tasks:
1: factorial
2: 2^number
3: 2^n1 + 2^n2
4: 2^n1 - 2^n2
5: fibonacci)"
            << std::endl;
}

void Task1()
{
  uint64_t n = 0;
  std::cout << "Input number to calculate factorial from: " << std::endl;
  std::cin >> n;
  std::cout << "Factorial of " << n << " is " << fact(n) << std::endl;
}

void Task2()
{
  uint64_t n = 0;
  std::cout << "Input number to calculate 2^number from: " << std::endl;
  std::cin >> n;
  std::cout << "2^" << n << " is " << powered2(n) << std::endl;
}

void Task3()
{
  uint64_t n1 = 0, n2 = 0;
  std::cout << "Input n1 and n2 to calculate 2^n1 + 2^n2: " << std::endl;
  std::cin >> n1 >> n2;
  std::cout << "2^" << n1 << "+2^" << n2 << " is " << (powered2(n1) + powered2(n2)) << std::endl;
}

void Task4()
{
  uint64_t n1 = 0, n2 = 0;
  std::cout << "Input n1 and n2 to calculate 2^n1 - 2^n2: " << std::endl;
  std::cin >> n1 >> n2;
  std::cout << "2^" << n1 << "-2^" << n2 << " is " << (powered2(n1) - powered2(n2)) << std::endl;
}

void Task5()
{
  uint64_t n = 0;
  std::cout << "Input number to calculate fibonacci from: " << std::endl;
  std::cin >> n;
  std::cout << "Fibonacci of " << n << " is " << fibonacci(n) << std::endl;
}

int main(int argc, char* argv[])
{
  if(argc <= 1)
  {
    PrintHelp(argv);
    return 0;
  }

  switch(argv[1][0])
  {
    case '1':
      Task1();
      break;
    case '2':
      Task2();
      break;
    case '3':
      Task3();
      break;
    case '4':
      Task4();
      break;
    case '5':
      Task5();
      break;
    default:
      std::cout << "Unknown usage!" << std::endl;
      break;
  }
  return 0;
}
