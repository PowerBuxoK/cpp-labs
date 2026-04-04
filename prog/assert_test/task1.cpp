#include "task1.h"
#include <cassert>
#include <iostream>

void task1_test_general()
{
  assert(task1(10, 5) == 6);
  assert(task1(10, 9) == 10);
  assert(task1(10, 10) == 9);
}

void task1_test_1person()
{
  assert(task1(1, 100) == 1);
}

int main(int argc, char* argv[])
{
  std::cout << "Task1 test general" << std::endl;
  task1_test_general();
  std::cout << "OK" << std::endl;
  std::cout << "Task1 test 1 person" << std::endl;
  task1_test_1person();
  std::cout << "OK" << std::endl;

  return 0;
}
