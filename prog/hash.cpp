#include "hash.h"

uint64_t custom_hash(const std::string& to_hash, uint64_t size_limit)
{
  uint64_t hash = 0;

  for(const char& v : to_hash)
  {
    hash += v;
    hash += __builtin_popcount(hash);
    hash ^= v;
    hash *= v;
  }

  return hash % size_limit;
}
