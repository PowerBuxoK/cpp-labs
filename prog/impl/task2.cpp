#include "./task2.h"
#include <algorithm>
#include <cstdlib>

bool task2(int sx, int sy, int fx, int fy, unsigned int t)
{
  // Compute deltas
  int dx = abs(fx - sx);
  int dy = abs(fy - sy);

  int minSteps = std::max(dx, dy);

  // If the distance is too long
  if(t < minSteps)
    return false;
  // Or if we started where we need to end up
  // and have not enough steps to get back
  if(dx == 0 && dy == 0 && t == 1)
    return false;

  // Otherwhise we can always circle around to
  // get desired number of steps
  return true;
}
