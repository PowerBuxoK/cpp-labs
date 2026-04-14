#pragma once
#include <iostream>
#include <string>
#include <vector>

class HashTable
{
private:
  struct Entry
  {
    std::string key = "";
    double value    = 0;
    bool occupied   = false;
  };

  std::vector<Entry> m_table;
  int m_capacity;
  int m_currentSize;

public:
  HashTable();
  HashTable(int cap);
  ~HashTable();

  bool add(const std::string& key, double value);
  bool remove(const std::string& key);
  bool find(const std::string& key, double& value) const;

  bool isEmpty() const;
  int size() const;

  void print() const;
};
;
