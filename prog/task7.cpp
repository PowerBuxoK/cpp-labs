#include "task7.h"

int task7(const int n)
{
  // dp[i] = количество бинарных строк длины i без "11"
  int dp[32];
  dp[0] = 1;
  dp[1] = 2;

  for(int i = 2; i < 32; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  int result  = 0;
  int prevBit = 0;

  for(int i = 30; i >= 0; i--)
  {
    if(n & (1 << i))
    {
      result += dp[i];

      if(prevBit == 1)
      {
        // встретили "11" в самом n
        return result;
      }

      prevBit = 1;
    }
    else
    {
      prevBit = 0;
    }
  }

  return result + 1;
}
