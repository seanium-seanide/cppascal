#include "Interpreter.h"

Interpreter::Interpreter(std::string text)
: m_text(text)
, m_pos(0)
, m_currentToken(nullptr)
{
  (void) m_text;
  (void) m_pos;
  (void) m_currentToken;
}

Interpreter::~Interpreter()
{
}

std::string Interpreter::expr() const
{
  return "";
}
