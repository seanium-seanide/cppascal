#ifndef CLASS_TOKEN_H
#define CLASS_TOKEN_H

#include <ostream>
#include <string>

#include "constants.h"

class Token
{
public:

  Token(std::string type, int value);
  ~Token();

  friend std::ostream &operator<<(std::ostream &out, const Token &token);

private:

  std::string m_type;
  int m_value;

  std::string to_string() const;
};

#endif
