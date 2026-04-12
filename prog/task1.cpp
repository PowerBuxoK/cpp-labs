#include "task1.h"
#include "HashTable.h"
#include "hash.h"
#include <fstream>
#include <string>

HashTable table;
int duplicates = 0;

void enrolled(std::string filepath)
{
  std::ifstream file(filepath);
  std::string line;
  while(getline(file, line))
  {
    table.insert(line);
  }
}

void unenrolled(std::string name)
{
}

void task1() {

};
