#include <numeric>

bool task5(unsigned int fx, unsigned int fy)
{
  if(fx == 0 && fy == 0)
    return false;

  // Greatest common divisor
  unsigned int g = std::gcd(fx, fy);

  // Check wether g is 2 to some power
  return (g & (g - 1)) == 0;
}
