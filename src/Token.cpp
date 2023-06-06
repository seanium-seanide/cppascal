#include "Token.h"

Token::Token(std::string type, int value)
: m_type(type)
, m_value(value)
{
  (void) m_type;
  (void) m_value;
}

Token::~Token()
{
}

std::ostream &operator<<(std::ostream &out, const Token &token)
{
  out << token.to_string();

  return out;
}

std::string Token::to_string() const
{
  std::string retval = "";

  retval += "Token(";
  retval += m_type;
  retval += ", ";
  retval += std::to_string(m_value);
  retval += ")";

  return retval;
}
