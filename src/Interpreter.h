#ifndef CLASS_INTERPRETER_H
#define CLASS_INTERPRETER_H

#include <string>

#include "Token.h"

class Interpreter
{
public:

  Interpreter(std::string text);
  ~Interpreter();

  void        error();
  std::string expr() const;

  /**
   * @brief Tokenises the string passed as input. Yields the next toen for
   *        parsing.
   */
  Token       *getNextToken();

private:

  std::string             m_text;
  std::string::size_type  m_pos;
  Token                   *m_currentToken;
};

#endif
