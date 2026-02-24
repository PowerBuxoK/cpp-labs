#pragma once
#include <cinttypes>
#include <cstdint>
#include <limits>
#include <string>
#include <vector>

/*
 * A convinient big integer class
 */
class LongInt
{
public:
  // Initializes from a regular number
  LongInt(uint64_t a);
  // Set operator
  LongInt& operator=(uint64_t val);
  // In-place addition
  LongInt& operator+=(const LongInt& rhs);
  // Regular addition
  friend LongInt operator+(LongInt lhs, const LongInt& rhs);
  // In-place subtraction
  LongInt& operator-=(const LongInt& rhs);
  // Regular subtraction
  friend LongInt operator-(LongInt lhs, const LongInt& rhs);
  // In-place multiplication
  LongInt& operator*=(uint64_t rhs);
  // Regular multiplication
  friend LongInt operator*(LongInt lhs, const uint64_t& rhs);

  friend std::ostream& operator<<(std::ostream& os, const LongInt& li);

private:
  //															This thing is like this
  //															so that it is easy to
  //															convert to string
  static constexpr uint64_t BASE = 10000000000000000ULL;
  /*
   * Cuts the internal vector to its lowest possible size
   */
  void Shorten();
  std::vector<uint64_t> m_val;
};

LongInt fact(uint64_t n);
LongInt powered2(uint64_t n);
LongInt fibonacci(uint64_t n);
