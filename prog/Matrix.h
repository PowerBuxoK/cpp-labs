#pragma once
#include <ostream>
#include <vector>

class Matrix
{
public:
  Matrix();
  Matrix(const int& x, const int& y, bool do_fill_with_garbage = true);
  ~Matrix();
  int Rows() const;
  int Columns() const;

  bool SizeEquals(const Matrix& rhs);

  int Maximum();

  Matrix& operator=(const Matrix& rhs);

  friend bool operator==(Matrix lhs, const Matrix& rhs);
  friend Matrix operator+(Matrix lhs, const Matrix& rhs);
  friend Matrix operator-(Matrix lhs, const Matrix& rhs);
  friend Matrix operator*(Matrix lhs, const int& rhs);
  friend Matrix operator*(Matrix lhs, const Matrix& rhs);

  friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
  friend std::istream& operator>>(std::istream& os, Matrix& mat);

  std::vector<std::vector<int>> m_values;

protected:
  void FillWithGarbage();
  int GetLongestInColumn(const int& col) const;

  int m_width, m_height;
};
