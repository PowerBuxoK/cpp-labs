#include "task3.h"
#include <iostream>

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
  try
  {
    func4();
  }
  catch(const int e)
  {
    std::cerr << "Int exception" << e << '\n';
  }
  std::cout << "func3 end" << std::endl;
}

void func2()
{
  std::cout << "func2" << std::endl;
  try
  {
    try
    {
      func3();
    }
    catch(const int e)
    {
      std::cerr << "Int exception" << e << '\n';
    }
  }
  catch(const double e)
  {
    std::cerr << "Double exception" << std::endl;
  }
  std::cout << "func2 end" << std::endl;
}

void func1()
{
  std::cout << "func1" << std::endl;
  func2();
  std::cout << "func1 end" << std::endl;
}
