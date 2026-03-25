#include "Matrix.h"
#include "SquareMatrix.h"
#include <iostream>

void test_out()
{
  Matrix mat;
  std::cout << "mat printout: " << std::endl;
  std::cout << mat << std::endl;
}

void test_in()
{
  Matrix mat(3, 3);
  std::cout << "Input 3x3 matrix:" << std::endl;
  std::cin >> mat;
  std::cout << "mat printout: " << std::endl;
  std::cout << mat << std::endl;
}

void test_add()
{
  std::cout << "Matrix addition" << std::endl;
  Matrix mat1(3, 3);
  Matrix mat2(3, 3);
  std::cout << "mat1:\n"
            << mat1 << std::endl;
  std::cout << "mat2:\n"
            << mat2 << std::endl;
  std::cout << "mat1+mat2:\n"
            << (mat1 + mat2) << std::endl;
}

void test_sub()
{
  std::cout << "Matrix subtraction" << std::endl;
  Matrix mat1(3, 3);
  Matrix mat2(3, 3);
  std::cout << "mat1:\n"
            << mat1 << std::endl;
  std::cout << "mat2:\n"
            << mat2 << std::endl;
  std::cout << "mat1-mat2:\n"
            << (mat1 - mat2) << std::endl;
}

void test_mul_num()
{
  std::cout << "Matrix multiplication by number" << std::endl;
  Matrix mat(3, 3);
  std::cout << "mat:\n"
            << mat << std::endl;
  std::cout << "mat * 3:\n"
            << (mat * 3) << std::endl;
}

void test_mul_mat()
{
  std::cout << "Matrix multiplication" << std::endl;
  Matrix mat1(3, 3);
  Matrix mat2(3, 3);
  std::cout << "mat1:\n"
            << mat1 << std::endl;
  std::cout << "mat2:\n"
            << mat2 << std::endl;
  std::cout << "mat1*mat2:\n"
            << (mat1 * mat2) << std::endl;
}

void test_mat_assign()
{
  std::cout << "Matrix assigment" << std::endl;
  Matrix mat1(3, 3);
  Matrix mat2(3, 3);
  std::cout << "mat1:\n"
            << mat1 << std::endl;
  std::cout << "mat2 before assigment:\n"
            << mat2 << std::endl;
  mat2 = mat1;
  std::cout << "mat2 after assigment:\n"
            << (mat2) << std::endl;
}

void test_equality()
{
  std::cout << "Matrix equality" << std::endl;
  Matrix mat1(3, 3);
  Matrix mat2(3, 3);
  Matrix mat3 = mat1;
  std::cout << "mat1:\n"
            << mat1 << std::endl;
  std::cout << "mat2:\n"
            << mat2 << std::endl;
  std::cout << "mat3:\n"
            << mat3 << std::endl;
  std::cout << "mat1==mat2:\n"
            << (mat1 == mat2 ? "true" : "false") << std::endl;
  std::cout << "mat1==mat3:\n"
            << (mat1 == mat3 ? "true" : "false") << std::endl;
}

void test_symetrical()
{
  std::cout << "sqr Matrix symmetricity:" << std::endl;
  SquareMatrix mat1(3);
  mat1.m_values = {
    { 0, 1, 2 },
    { 1, 0, 1 },
    { 2, 1, 0 },
  };
  std::cout << "mat1:\n"
            << mat1 << std::endl;
  std::cout << "Is " << (mat1.isSymmetrical() ? "Symmetrical" : "Non-symmetrical") << std::endl
            << std::endl;
}

void test_det()
{
  std::cout << "sqr Matrix determenant:" << std::endl;
  SquareMatrix mat1(3);
  std::cout << "mat1:\n"
            << mat1 << std::endl;
  std::cout << "det(mat1) = " << mat1.det() << std::endl;
}

void test_power()
{
  std::cout << "sqr Matrix power:" << std::endl;
  SquareMatrix mat1(3);
  std::cout << "mat1:\n"
            << mat1 << std::endl;
  mat1.power(2);
  std::cout << "mat1^2: \n" << mat1 << std::endl;
}

int main()
{
  test_out();
  test_in();
  test_add();
  test_sub();
  test_mul_num();
  test_mul_mat();
  test_mat_assign();
  test_equality();
  test_symetrical();
  test_det();
  test_power();
  return 0;
}