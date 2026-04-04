#include "task4.h"
#include <climits>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

int timeToMinutes(const std::string& time)
{
  int h, m;
  if(std::sscanf(time.c_str(), "%d:%d", &h, &m) == EOF)
  {
    throw std::invalid_argument("Incorrect format!");
  }
  return h * 60 + m;
}

int task4(std::vector<std::string> times)
{
  unsigned int min_delta = UINT_MAX;
  for(size_t i = 0; i < times.size(); i++)
  {
    int curtime = timeToMinutes(times[i]);
    for(size_t j = 0; j < times.size(); j++)
    {
      if(i == j)
        continue;
      int sectime = timeToMinutes(times[j]);

      unsigned int curdelta = abs(sectime - curtime);

      if(curdelta < min_delta)
        min_delta = curdelta;
    }
  }
  return min_delta;
};
