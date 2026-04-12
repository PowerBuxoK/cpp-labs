#pragma once
#include "hash.h"
#include <iostream>
#include <string>
#include <vector>

class HashTable
{
private:
  std::vector<std::string> m_table;
  std::vector<bool> m_occupied;
  size_t m_size;

  static const int TABLE_SIZE = 1024;

public:
  HashTable();

  bool insert(const std::string& key);
  void print();
  int size() const
  {
    return m_size;
  }
};
