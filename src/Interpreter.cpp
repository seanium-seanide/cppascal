#include "Interpreter.h"

#include <stdexcept>

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

void Interpreter::error()
{
  throw std::runtime_error("Error parsing input");
}

std::string Interpreter::expr() const
{
  return "";
}
