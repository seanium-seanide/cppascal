#include "Interpreter.h"

#include <stdexcept>
#include <cctype>

#include "token_constants.h"

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

Token *Interpreter::getNextToken()
{
  // Local copy of text member variable
  std::string text(m_text);

  if (m_pos > text.size())
  {
    return new Token(END_OF_FILE, -1);
  }

  char currentChar = text[m_pos];
    
  if (std::isdigit(currentChar))
  {
    Token *token = new Token(INTEGER, currentChar - '0');
    m_pos += 1;
    return token;
  }

  if (currentChar == '+')
  {
    Token *token = new Token(PLUS, currentChar);
    m_pos += 1;
    return token;
  }

  error();

  // Should not reach here!
  return nullptr;
}

void Interpreter::eat(std::string type)
{
  if (m_currentToken->getType() == type)
  {
    delete m_currentToken;
    m_currentToken = nullptr;

    m_currentToken = getNextToken();
  }

  error();
}

std::string Interpreter::expr() const
{
  return "";
}
