#include "Matrix.h"
#include "SquareMatrix.h"
#include <iostream>

// TODO: separate to many files

int main(int argc, char const* argv[])
{
  SquareMatrix mat(3);
  std::cin >> mat;
  std::cout << "\n"
            << mat << "\ndot\n"
            << mat.det() << std::endl;
  return 0;
}
