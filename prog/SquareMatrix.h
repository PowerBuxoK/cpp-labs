#pragma once
#include "Matrix.h"

class SquareMatrix : public Matrix
{
public:
  SquareMatrix(int size);

  bool isSymmetrical() const;
  void power(const int& power);
  long long det() const;
};
