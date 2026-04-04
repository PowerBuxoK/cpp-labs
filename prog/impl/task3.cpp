#include "./task3.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

// A little bit overbuilt but ok
namespace task3parser
{

  enum class TokenType
  {
    oper,
    lit,
    var,
    null,
  };

  struct Token
  {
    TokenType type;
    std::string value;
  };

  std::vector<Token> tokenize(const std::string& eq, size_t limit_left, size_t limit_right)
  {
    std::vector<Token> result;
    for(int i = limit_left; i < std::min(eq.size(), limit_right);)
    {
      char c = eq[i];
      // eat + and - as opeartors
      if(c == '+' || c == '-')
      {
        result.emplace_back(Token{
            TokenType::oper, { c } });
        i++;
      }
      // eat numbers as literals
      else if(std::isdigit(c))
      {
        std::string val;
        while(std::isdigit(eq[i]))
        {
          val += eq[i];
          i++;
        }
        result.emplace_back(Token{ TokenType::lit, val });
      }
      // eat x as x
      else if(c == 'x')
      {
        result.emplace_back(Token{
            TokenType::var, "x" });
        i++;
      }
      // eat unknown symbols but dont use them
      else
        i++;
    }
    return result;
  }

  struct ParseResult
  {
    int coefficent = 0;
    int constant   = 0;
  };

  void printToken(Token v)
  {
    switch(v.type)
    {
      case TokenType::lit:
        std::cout << "Literal: " << v.value << std::endl;
        break;
      case TokenType::oper:
        std::cout << "Operator: " << v.value << std::endl;
        break;
      case TokenType::var:
        std::cout << "Var: " << v.value << std::endl;
        break;
      case TokenType::null:
      default:
        std::cout << "Null: " << v.value << std::endl;
    }
  }

  // Parser is defined only in c++ file because we dont need to use it anywhere else.
  class Parser
  {
  private:
    std::vector<Token> m_tokens;
    unsigned int m_offset = 0;

  public:
    Parser(std::string eq, size_t limit_left, size_t limit_right)
        : m_tokens(tokenize(eq, limit_left, limit_right)) {
            // std::cout << "Tokens: " << std::endl;
            // for(auto& v : m_tokens)
            // {
            //   printToken(v);
            // }
          };

    ParseResult parse()
    {
      ParseResult result;
      int sign          = 1;
      int last_constant = 1;
      Token cur;
      while((cur = peek()).type != TokenType::null)
      {
        if(cur.type != TokenType::var)
          last_constant = 1;

        if(cur.type == TokenType::oper)
        {
          if(cur.value == "+")
            sign = 1;
          else if(cur.value == "-")
            sign = -1;
          consume();
        }
        else if(cur.type == TokenType::lit)
        {
          last_constant = std::stoll(cur.value) * sign;
          result.constant += last_constant;
          consume();
        }
        else if(cur.type == TokenType::var)
        {
          result.constant -= last_constant;
          result.coefficent += last_constant;
          last_constant = 1;
          consume();
        }
      }

      return result;
    }

  private:
    Token consume()
    {
      m_offset++;
      if(m_offset >= size())
      {
        return { TokenType::null, "" };
      }
      Token data = m_tokens.at(m_offset);
      return data;
    };
    Token peek(int delta = 0) const
    {
      if((unsigned int)(m_offset + delta) >= size())
      {
        return { TokenType::null, "" };
      }
      return m_tokens.at(m_offset + delta);
    }
    int size() const { return m_tokens.size(); }
  };
}

std::string task3(const std::string& equation)
{
  size_t eq_sign_pos = equation.find("=");
  if(eq_sign_pos == std::string::npos)
    throw std::invalid_argument("No valid equation specified!");
  task3parser::Parser parser_lhs(equation, 0, eq_sign_pos);
  task3parser::Parser parser_rhs(equation, eq_sign_pos, std::numeric_limits<size_t>::max());

  auto lhs = parser_lhs.parse();
  auto rhs = parser_rhs.parse();

  int coef = lhs.coefficent - rhs.coefficent;
  int res  = rhs.constant - lhs.constant;
  std::cout << "lhs: " << lhs.coefficent << "  " << lhs.constant << std::endl;
  std::cout << "rhs: " << rhs.coefficent << "  " << rhs.constant << std::endl;

  if(coef == 0)
  {
    if(res == 0)
      return "Infinite";
    return "NO";
  }

  // нужно целое решение
  if(res % coef != 0)
    return "NO";

  int x = res / coef;
  return "x=" + std::to_string(x);

  return "t3e";
};
