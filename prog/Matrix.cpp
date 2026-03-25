#include "Matrix.h"
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <ratio>
#include <stdexcept>

std::mt19937_64 int_rng(1312312);
std::uniform_int_distribution<int> int_dist(-100, 100);

Matrix::Matrix()
    : Matrix(2, 2)
{
}

Matrix::~Matrix()
{
  // destructor of m_values is called automatically
}

Matrix::Matrix(const int& x, const int& y, bool do_fill_with_garbage)
    : m_width(x), m_height(y)
{
  if(m_width < 1 || m_height < 1)
  {
    throw std::invalid_argument("Matrix size is less than 1x1");
  }

  m_values.resize(m_height, std::vector<int>(m_width, 0));

  if(do_fill_with_garbage)
    FillWithGarbage();
}

void Matrix::FillWithGarbage()
{
  for(auto& row : m_values)
    for(auto& val : row)
      val = int_dist(int_rng);
}

int Matrix::Columns() const
{
  return m_width;
}

int Matrix::Rows() const
{
  return m_height;
}

int Matrix::Maximum()
{
  int max = INT_MIN;
  for(auto& row : m_values)
  {
    for(auto& val : row)
    {
      max = std::max(max, val);
    }
  }
  return max;
}

int Matrix::GetLongestInColumn(const int& col) const
{
  int max = INT_MIN;
  for(int y = 0; y < m_height; y++)
  {
    int value = m_values[col][y];
    int len   = (value == 0 ? 1 : ((int)(log10(fabs(value)) + 1) + (value < 0 ? 1 : 0)));
    max       = std::max(max, len);
  }
  return max;
}

bool Matrix::SizeEquals(const Matrix& rhs)
{
  return m_width == rhs.Columns() && m_height == rhs.Rows();
}

Matrix operator+(Matrix lhs, const Matrix& rhs)
{
  if(!lhs.SizeEquals(rhs))
    throw std::invalid_argument("Matrix sizes not equal");
  const int w = lhs.m_width, h = lhs.m_height;
  Matrix result(lhs.m_width, lhs.m_height);
  for(int col = 0; col < w; col++)
  {
    for(int row = 0; row < h; row++)
      result.m_values[col][row] = lhs.m_values[col][row] + rhs.m_values[col][row];
  }
  return result;
}

Matrix operator-(Matrix lhs, const Matrix& rhs)
{
  if(!lhs.SizeEquals(rhs))
    throw std::invalid_argument("Matrix sizes not equal");
  const int w = lhs.m_width, h = lhs.m_height;
  Matrix result(lhs.m_width, lhs.m_height);
  for(int col = 0; col < w; col++)
  {
    for(int row = 0; row < h; row++)
      result.m_values[col][row] = lhs.m_values[col][row] - rhs.m_values[col][row];
  }
  return result;
}

Matrix& Matrix::operator=(const Matrix& rhs)
{
  // Dont do anything when trying to write to itself
  if(this == &rhs)
    return *this;
  m_values = rhs.m_values; // Copy values
  // Copy size
  m_width  = rhs.m_width;
  m_height = rhs.m_height;
  return *this;
}

bool operator==(Matrix lhs, const Matrix& rhs)
{
  if(!lhs.SizeEquals(rhs))
    return false;

  const int w = rhs.m_width, h = rhs.m_height;

  for(int col = 0; col < w; col++)
    for(int row = 0; row < h; row++)
      if(lhs.m_values[col][row] != rhs.m_values[col][row])
        return false;

  return true;
}

Matrix operator*(Matrix lhs, const int& rhs)
{
  const int w = lhs.m_width, h = lhs.m_height;
  Matrix result(lhs.m_width, lhs.m_height);

  for(int col = 0; col < w; col++)
    for(int row = 0; row < h; row++)
      result.m_values[col][row] = lhs.m_values[col][row] * rhs;
  return result;
}

Matrix operator*(Matrix lhs, const Matrix& rhs)
{
  const int w1 = lhs.Columns(), h1 = lhs.Rows();
  const int w2 = rhs.Columns(), h2 = rhs.Rows();

  Matrix result(h2, w2, false);

  if(w1 != h2)
    throw std::invalid_argument("Incompatible matrix sizes!");

  for(int i = 0; i < h1; i++)
  {
    for(int j = 0; j < w2; j++)
    {
      for(int k = 0; k < w1; k++)
      {
        result.m_values[i][j] += lhs.m_values[i][k] * rhs.m_values[k][j];
      }
    }
  }

  return result;
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat)
{
  // Calculate max column widths
  int* collengths = new int[mat.m_width];
  for(int col = 0; col < mat.m_width; col++)
  {
    collengths[col] = mat.GetLongestInColumn(col);
  }

  for(int row = 0; row < mat.m_height; row++)
  {
    for(int col = 0; col < mat.m_width; col++)
    {
      int maxlen = collengths[col];
      int value  = mat.m_values[col][row];
      os << "[" << std::setw(maxlen) << value << "]";
    }
    os << "\n";
  }
  return os;
}

std::istream& operator>>(std::istream& is, Matrix& mat)
{

  for(int row = 0; row < mat.m_height; row++)
    for(int col = 0; col < mat.m_width; col++)
      is >> mat.m_values[col][row];

  return is;
}
