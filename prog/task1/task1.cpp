#include "task1.h"
#include "hash.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int duplicates = 0;
int voters     = 0;

int get_duplicates()
{
  return duplicates;
}

int get_voters()
{
  return voters;
}

struct entry_t
{
  std::string name;
  bool valid;
};

std::vector<entry_t> table(255, { .name = "", .valid = false });

bool try_insert(const std::string& to_insert)
{
  const auto hash = custom_hash(to_insert, table.size());
  if(table[hash].valid)
    return false;
  table[hash].name  = to_insert;
  table[hash].valid = true;
  return true;
}

bool enrolled(std::string filepath)
{
  std::ifstream file(filepath);
  if(!file.is_open())
  {
    std::cout << "failed to open file " << filepath << std::endl;
    return false;
  }
  std::string line;
  while(getline(file, line))
  {
    if(!try_insert(line))
      duplicates++;
    else
      voters++;
  }
  return true;
}

void unenrolled(std::string name)
{
  if(!try_insert(name))
    duplicates++;
  else
    voters++;
}

void task1()
{
  std::cout << "Enter file to enroll" << std::endl;
  {
    std::string filepath;
    std::getline(std::cin, filepath);
    while(!enrolled(filepath))
    {
      std::cout << "Enter valid file to enroll!" << std::endl;
      std::getline(std::cin, filepath);
    };
  }
  std::cout << "Enter name to unenroll" << std::endl;
  std::string line;

  while(true)
  {
    getline(std::cin, line);
    if(line == "end")
      break;
    unenrolled(line);
  }

  std::cout << "Voters: " << voters << std::endl;
  for(auto& v : table)
    if(v.valid)
      std::cout << v.name << "\n";
  std::cout << "Duplicates: " << duplicates << std::endl;
};

void print_names()
{
  for(auto& v : table)
    if(v.valid)
      std::cout << v.name << "\n";
}
