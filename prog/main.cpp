#include "task8.h"
#include <iostream>
#include <string>

int main(int argc, char const* argv[])
{
  auto res = task8({
      { 0,  0 },
      { 5,  5 },
      { 10, 4 },
  });

  for(auto& b : res)
  {
    std::cout << b.first << "   " << b.second << std::endl;
  }

  return 0;
}
