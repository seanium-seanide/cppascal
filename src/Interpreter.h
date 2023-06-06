#ifndef CLASS_INTERPRETER_H
#define CLASS_INTERPRETER_H

#include <string>

#include "Token.h"

class Interpreter
{
public:

  Interpreter(std::string text);
  ~Interpreter();

  void error();
  std::string expr() const;
  void getNextToken();

private:

  std::string m_text;
  int m_pos;
  Token *m_currentToken;
};

#endif
