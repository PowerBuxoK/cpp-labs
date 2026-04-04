#include "task8.h"
#include <climits>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> task8(std::vector<std::pair<int, int>> bushes)
{
  std::vector<std::pair<int, int>> result;
  std::pair<int, int> aabb_min = { INT_MAX, INT_MAX };
  std::pair<int, int> aabb_max = { INT_MIN, INT_MIN };

  // Find minimum and maximum positions
  for(auto& bush : bushes)
  {
    aabb_min.first  = std::min(aabb_min.first, bush.first);
    aabb_min.second = std::min(aabb_min.second, bush.second);
    aabb_max.first  = std::max(aabb_max.first, bush.first);
    aabb_max.second = std::max(aabb_max.second, bush.second);
  }

  // Find bushes that are on the border
  for(auto& bush : bushes)
  {
    // clang-format off
    bool on_border = bush.first == aabb_min.first
			|| bush.second == aabb_min.second
			||bush.first == aabb_max.first
			|| bush.second == aabb_min.second;
    // clang-format on
    if(on_border)
      result.emplace_back(bush);
  }

  return result;
};
