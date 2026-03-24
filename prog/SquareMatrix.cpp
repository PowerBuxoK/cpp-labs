#include "SquareMatrix.h"
#include "iostream"
#include <cmath>

SquareMatrix::SquareMatrix(int size)
    : Matrix(size, size)
{
}

void SquareMatrix::power(const int& power)
{
  for(auto& row : m_values)
    for(auto& val : row)
      val = (int)(std::pow(val, power) + 1e-9);
}

bool SquareMatrix::isSymmetrical() const
{
  for(int col = 0; col < Columns(); col++)
    for(int row = 0; row < Rows(); row++)
      if(m_values[col][row] != m_values[row][col])
        return false;

  return true;
}

long long SquareMatrix::det() const
{
  int size = Columns();
  int sign = 1;

  // A temporary matrix
  std::vector<std::vector<long long>> a(size, std::vector<long long>(size));
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      a[i][j] = m_values[i][j];
    }
  }

  long long prev = 1;

  for(int i = 0; i < size - 1; i++)
  {
    int pivot = i;
    while(pivot < size && a[pivot][i] == 0)
    {
      pivot++;
    }

    if(pivot == size)
    {
      return 0;
    }

    if(pivot != i)
    {
      std::swap(a[i], a[pivot]);
      sign = -sign;
    }

    long long pivotValue = a[i][i];

    for(int j = i + 1; j < size; j++)
    {
      for(int k = i + 1; k < size; k++)
      {
        a[j][k] = (a[j][k] * pivotValue - a[j][i] * a[i][k]) / prev;
      }
    }

    prev = pivotValue;
  }

  return sign * a[size - 1][size - 1];
}
