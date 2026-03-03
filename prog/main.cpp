#include <cinttypes>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

void PrintHelp(char* argv[])
{
  std::cout << "Program usage: \n"
            << argv[0] << R"( [task]

Tasks:
1: Replace . to [.] in IP
2: Palandrome detection
3: Letter counting)"
            << std::endl;
}

bool ValidateIP(const std::string& input_ip)
{
  // Check wether the IP follows a %d.%d.%d.%d template
  int dot_count = 0;
  size_t last_dot_pos = 0;
  for(size_t i = 0; i < input_ip.size(); i++)
  {
    char c = input_ip[i];
    if (c == '.' && last_dot_pos + 1 == i) {
      std::cout << "IP malformed! (Number " << dot_count + 1 << " is empty)" << std::endl;
      return false;
    }
    if(c == '.' && (i + 1) < input_ip.size())
    {
      dot_count++;
      last_dot_pos = i;
    }
    else if(!std::isdigit(c))
    {
      std::cout << "IP malformed!" << std::endl;
      return false;
    }
  }

  if(dot_count != 3)
  {
    std::cout << "IP malformed! (Dot count not equal to 3)" << std::endl;
    return false;
  }

  {
    uint16_t output[4] = { 0 };
    sscanf(input_ip.c_str(), "%d.%d.%d.%d", &output[0], &output[1], &output[2], &output[3]);
    for(size_t i = 0; i < sizeof(output) / sizeof(*output); i++)
    {
      if(output[i] > 255)
      {
        std::cout << "IP malformed! (Component " << i + 1 << " greater than 255)" << std::endl;
        return false;
      }
    }
  }

  return true;
}

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
  size_t start_pos = 0;
  while((start_pos = str.find(from, start_pos)) != std::string::npos)
  {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length();
  }
  return str;
}

void Block1Task2()
{
  std::string input_ip;
  std::cout << "Input a IPv4 IP:" << std::endl;
  std::cin >> input_ip;

  if(!ValidateIP(input_ip))
  {
    return;
  }

  std::cout << "Replaced: " << ReplaceAll(input_ip, ".", "\"[.]\"") << std::endl;
}

bool IsPalandrome(const std::string& cs)
{
  // We dont need to check the middle letter
  // Because it has no effect on the result
  // The middle letter is excluded at the division
  // of string size by two. For example:
  // string size = 5
  // After division we have 2, not including
  // the middle char
  for(size_t i = 0; i < cs.size() / 2; i++)
  {
    if(cs[i] != cs[cs.size() - i - 1])
    {
      return false;
    }
  }
  return true;
}

void Block2Task1()
{
  std::string input;
  std::getline(std::cin, input);
  std::string nwv = ReplaceAll(input, " ", "");
  std::cout << "The sentance \"" << input << "\" " << (IsPalandrome(nwv) ? "is a palandrome" : "is not a palandrome") << std::endl;
}

std::vector<int> Block3Function(const std::string& words, const std::vector<char>& letters)
{
  std::vector<int> score(26);

  // Search string words for every letter in vector letters
  for(char to_count : letters)
  {
    for(char c : words)
    {
      if(!std::isalpha(c))
      {
        std::cout << "Character '" << c << "' will be ignored" << std::endl;
        continue;
      }
      if(c != to_count)
        continue;
      char c_lower = std::tolower(c);
      score[c_lower - 'a']++;
    }
  }

  return score;
}

void Block3()
{
  std::string words;
  std::vector<char> letters;

  std::cout << "Input letters to count" << std::endl;
  {
    std::string ltr_str;
    std::cin >> ltr_str;
    for(char& c : ltr_str)
    {
      if(!std::isalpha(c))
      {
        std::cout << "The string should only contain letters char '" << c << "' will be ignored" << std::endl;
        continue;
      }
      letters.emplace_back(c);
    }
  }

  std::cout << "Words to count in" << std::endl;
  std::cin.ignore();
  getline(std::cin, words);

  auto score = Block3Function(words, letters);

  for(char i = 0; i < score.size(); i++)
  {
    std::cout << (char)('a' + i) << ": " << score[i] << std::endl;
  }
}

int main(int argc, char* argv[])
{
  if(argc <= 1)
  {
    PrintHelp(argv);
    return 0;
  }

  switch(argv[1][0])
  {
    case '1':
      Block1Task2();
      break;
    case '2':
      Block2Task1();
      break;
    case '3':
      Block3();
      break;
    default:
      std::cout << "Unknown usage!" << std::endl;
      break;
  }
  return 0;
}
