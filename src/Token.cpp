#include "Token.h"

std::ostream &operator<<(std::ostream &out, const Token &token)
{
  out << token.to_string();

  return out;
}

std::string Token::to_string() const
{
  return std::string("");
}

