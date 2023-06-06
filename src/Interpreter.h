#ifndef CLASS_INTERPRETER_H
#define CLASS_INTERPRETER_H

#include <string>

#include "Token.h"

class Interpreter
{
public:

  Interpreter(std::string text);
  ~Interpreter();

  /**
   * @brief Tokenises the string passed as input. Yields the next toen for
   *        parsing.
   */
  Token       *getNextToken();

  /**
   * @brief If current token is of given type, eat it and get the next token.
   *
   * @param[in] type  Token type with which to compare current token.
   */
  void eat(std::string type);

  /**
   * @brief TODO
   */
  std::string expr() const;

private:

  std::string             m_text;
  std::string::size_type  m_pos;
  Token                   *m_currentToken;

  /**
   * @brief Throw runtime exception.
   */
  void error();
};

#endif
