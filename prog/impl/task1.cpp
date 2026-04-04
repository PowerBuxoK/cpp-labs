#include "./task1.h"

unsigned int task1(unsigned int people_cnt, unsigned int time)
{
  if(people_cnt == 1)
    return 1;

  unsigned int period = 2LL * (people_cnt - 1);
  unsigned int k      = time % period;

  if(k <= people_cnt - 1)
    return 1 + k;
  else
    return 2 * people_cnt - 1 - k;
}
