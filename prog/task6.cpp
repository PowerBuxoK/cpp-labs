#include "task6.h"
#include <iostream>
#include <stdexcept>
#include <vector>

// A little bit overbuilt but ok №2

namespace task6parser
{

  enum class TokenType
  {
    oper,
    lit,
    lpar,
    rpar,
    null,
  };

  struct Token
  {
    TokenType type;
    std::string value;
  };

  std::vector<Token> tokenize(const std::string& eq)
  {
    std::vector<Token> result;
    for(int i = 0; i < eq.size();)
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
      else if(c == '(')
      {
        result.emplace_back(Token{
            TokenType::lpar, "(" });
        i++;
      }
      else if(c == ')')
      {
        result.emplace_back(Token{
            TokenType::rpar, ")" });
        i++;
      }
      // eat unknown symbols but dont use them
      else
        i++;
    }
    return result;
  }

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
      case TokenType::rpar:
      case TokenType::lpar:
        std::cout << "Par: " << v.value << std::endl;
        break;
      case TokenType::null:
      default:
        std::cout << "Null: " << v.value << std::endl;
    }
  }

  class Parser
  {
  private:
    std::vector<Token> m_tokens;
    unsigned int m_offset = 0;

  public:
    Parser(std::string eq)
        : m_tokens(tokenize(eq)) {
            // std::cout << "Tokens: " << std::endl;
            // for(auto& v : m_tokens)
            // {
            //   printToken(v);
            // }
          };

    int evaluateParenthesis()
    {
      int result    = 0;
      int sign      = 1;
      bool is_unary = true;
      Token cur;
      while((cur = peek()).type != TokenType::null)
      {
        switch(cur.type)
        {
          case TokenType::lit:
            result += std::stoll(cur.value) * sign;
            is_unary = false;
            consume();
            break;
          case TokenType::oper:
            if(cur.value == "+")
              if(!is_unary)
                sign = 1;
              else
                throw std::invalid_argument("+ cant be unary!");
            else if(cur.value == "-")
              sign = -1;
            consume();
            break;
          case TokenType::lpar:
            consume();
            result += evaluateParenthesis() * sign;
            break;
          case TokenType::rpar:
            return result;
            break;
          default:
            break;
        }
      }
      return result;
    }

    int solve()
    {
      int result = evaluateParenthesis();
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

int task6(const std::string equation)
{
  task6parser::Parser prs(equation);
  return prs.solve();
}
