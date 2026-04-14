#include "HashTable.h"
#include <cassert>
#include <iostream>

int main(int argc, char* argv[])
{
  HashTable table;
  {
    std::cout << "Test1" << std::endl;
    assert(table.isEmpty());
  };
  table.add("beet", 123.0);
  table.add("appel", 456.0);
  {
    std::cout << "Test2" << std::endl;
    double value;
    table.find("beet", value);
    assert(value == 123.0);
    table.find("appel", value);
    assert(value == 456.0);
  }
  {
    std::cout << "Test3" << std::endl;
    table.remove("appel");
    double value;
    assert(!table.find("appel", value));
  }
  std::cout << "OK" << std::endl;
  return 0;
}
