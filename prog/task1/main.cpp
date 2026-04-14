#include "task1.h"
#include <iostream>

int main(int argc, char* argv[])
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

  std::cout << "Voters: " << get_voters() << std::endl;
  print_names();
  std::cout << "Duplicates: " << get_duplicates() << std::endl;
  return 0;
}
