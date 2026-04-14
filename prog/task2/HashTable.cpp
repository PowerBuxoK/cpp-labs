#include "HashTable.h"
#include <iostream>

int customHash(const std::string& to_hash, int max_size)
{
  int hash = 0;

  for(const char& v : to_hash)
  {
    hash += v;
    hash += __builtin_popcount(hash);
    hash ^= v;
    hash *= v;
  }

  return abs(hash) % max_size;
}

HashTable::HashTable()
    : HashTable(10)
{
}

HashTable::HashTable(int cap)
{
  m_capacity    = cap;
  m_currentSize = 0;
  m_table.resize(m_capacity);
}

int HashTable::size() const
{
  return m_currentSize;
}

bool HashTable::isEmpty() const
{
  return m_currentSize == 0;
}

bool HashTable::add(const std::string& key, double value)
{
  int index = customHash(key, m_table.size());
  if(!m_table[index].occupied)
  {
    m_table[index].key      = key;
    m_table[index].value    = value;
    m_table[index].occupied = true;
    m_currentSize++;
    return true;
  }

  if(m_table[index].key == key)
  {
    m_table[index].value = value;
    return true;
  }

  return false;
}

bool HashTable::find(const std::string& key, double& value) const
{
  int index = customHash(key, m_table.size());

  if(m_table[index].occupied && m_table[index].key == key)
  {
    value = m_table[index].value;
    return true;
  }

  return false;
}

bool HashTable::remove(const std::string& key)
{
  int index = customHash(key, m_table.size());

  if(m_table[index].occupied && m_table[index].key == key)
  {
    m_table[index].occupied = false;
    m_table[index].key      = "";
    m_table[index].value    = 0;
    m_currentSize--;
    return true;
  }

  return false;
}

void HashTable::print() const
{
  for(int i = 0; i < m_capacity; i++)
  {
    std::cout << i << ": ";
    if(m_table[i].occupied)
    {
      std::cout << "[" << m_table[i].key << " : " << m_table[i].value << "]";
    }
    else
    {
      std::cout << "empty";
    }
    std::cout << std::endl;
  }
}
