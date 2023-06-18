#include "Interpreter.h"

#include <stdexcept>
#include <cctype>
#include <iostream>

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
  std::cerr << "### TOP OF eat() ###" << std::endl;

  if (m_currentToken->getType() == type)
  {
    std::cerr << "### TOP OF LOOP IN eat() ###" << std::endl;

    if (m_currentToken != nullptr)
    {
      std::cerr << "### TOKEN WAS NOT NULLPTR IN eat() ###" << std::endl;

      delete m_currentToken;

      std::cerr << "### TOKEN WAS FREED eat() ###" << std::endl;

      m_currentToken = nullptr;
    }

    std::cerr << "### getNextToken() about to be called from eat() ###" << std::endl;

    m_currentToken = getNextToken();

    std::cerr << "### RETURNING FROM eat() ###" << std::endl;

    return;
  }

  error();
}

std::string Interpreter::expr()
{
  m_currentToken = getNextToken();

  Token *leftOperand = m_currentToken;
  eat(INTEGER);

  Token *op = m_currentToken;
  (void) op;
  eat(PLUS);

  Token *rightOperand = m_currentToken;
  eat(INTEGER);

  int result = leftOperand->getValue() + rightOperand->getValue();

  return std::string(std::to_string(result));
}
