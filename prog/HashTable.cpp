#include "HashTable.h"
#include <string>

HashTable::HashTable()
{
  m_table.resize(TABLE_SIZE);
  m_occupied.resize(TABLE_SIZE, false);
}

bool HashTable::insert(const std::string& key)
{
  size_t index = custom_hash(key, TABLE_SIZE);

  for(int i = 0; i < TABLE_SIZE; i++)
  {
    size_t probe = (index + i) % TABLE_SIZE;

    if(!m_occupied[probe])
    {
      m_table[probe]    = key;
      m_occupied[probe] = true;
      m_size++;
      return true;
    }

    if(m_table[probe] == key)
    {
      return false;
    }
  }

  return false;
}

void HashTable::print()
{
  for(int i = 0; i < TABLE_SIZE; i++)
  {
    if(m_occupied[i])
    {
      std::cout << m_table[i] << std::endl;
    }
  }
}
