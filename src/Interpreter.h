#ifndef CLASS_INTERPRETER_H
#define CLASS_INTERPRETER_H

#include <string>

#include "Token.h"

class Interpreter
{
public:

  Interpreter(std::string text);
  ~Interpreter();

  std::string expr() const;

private:

  std::string m_text;
  int m_pos;
  Token *m_currentToken;
};

#endif
