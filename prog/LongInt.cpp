#include "LongInt.h"
#include <iomanip>
#include <iostream>

LongInt::LongInt(uint64_t a)
{
  *this = a;
}

void LongInt::Shorten()
{
  while(m_val.size() > 1 && m_val.back() == 0)
  {
    m_val.pop_back();
  }
}

LongInt& LongInt::operator=(uint64_t val)
{
  m_val.clear();

  do
  {
    m_val.emplace_back(val % BASE);
    val /= BASE;
  } while(val > 0);

  return *this;
};

LongInt& LongInt::operator+=(const LongInt& rhs)
{
  size_t new_size = std::max(m_val.size(), rhs.m_val.size());
  m_val.resize(new_size, 0);
  uint64_t carry = 0;

  for(size_t i = 0; i < new_size; ++i)
  {
    uint64_t op = carry + m_val[i] + (i < rhs.m_val.size() ? rhs.m_val[i] : 0ULL);
    m_val[i]    = op % BASE;
    carry       = op / BASE;
  }

  if(carry)
    m_val.emplace_back(carry);
  Shorten();
  return *this;
}

LongInt& LongInt::operator-=(const LongInt& rhs)
{
  int64_t carry = 0;
  for(size_t i = 0; i < m_val.size(); ++i)
  {
    int64_t cur = (int64_t)m_val[i] - (i < rhs.m_val.size() ? (int64_t)rhs.m_val[i] : 0) - carry;
    if(cur < 0)
    {
      cur += BASE;
      carry = 1;
    }
    else
    {
      carry = 0;
    }
    m_val[i] = cur;
  }
  Shorten();
  return *this;
}

LongInt& LongInt::operator*=(uint64_t rhs)
{
  if(rhs == 0)
  {
    *this = 0;
    return *this;
  }
  uint64_t carry = 0;
  for(size_t i = 0; i < m_val.size(); ++i)
  {
    uint64_t cur = carry + 1ULL * m_val[i] * rhs;
    m_val[i]     = cur % BASE;
    carry        = cur / BASE;
  }
  while(carry)
  {
    m_val.emplace_back(carry % BASE);
    carry /= BASE;
  }
  Shorten();
  return *this;
};

LongInt operator+(LongInt lhs, const LongInt& rhs)
{
  lhs += rhs;
  return lhs;
}

LongInt operator-(LongInt lhs, const LongInt& rhs)
{
  lhs -= rhs;
  return lhs;
}

LongInt operator*(LongInt lhs, const uint64_t& rhs)
{

  lhs *= rhs;
  return lhs;
}

std::ostream& operator<<(std::ostream& os, const LongInt& val)
{
  os << val.m_val.back();
  for(int i = val.m_val.size() - 2; i >= 0; i--)
  {
    os << std::setw(16) << std::setfill('0') << val.m_val.at(i);
  }
  return os;
}

LongInt fact(uint64_t v)
{
  LongInt result = 1;
  for(int i = 2; i <= v; ++i)
    result *= ((uint32_t)i);
  return result;
}

LongInt powered2(uint64_t v)
{
  LongInt result = 1;
  for(int i = 0; i < v; ++i)
    result *= 2;
  return result;
}

LongInt fibonacci(uint64_t v)
{
  if(v <= 2)
    return 1;
  LongInt a = 1, b = 1;
  for(int i = 3; i < v; i++)
  {
    LongInt c = a + b;

    a = b;
    b = c;
  }
  return b;
}
