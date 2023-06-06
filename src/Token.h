#ifndef CLASS_TOKEN_H
#define CLASS_TOKEN_H

#include <ostream>

class Token
{
public:

  Token();
  ~Token();

  friend std::ostream &operator<<(std::ostream &out, const Token &token);

private:

  std::string to_string() const;
};

#endif
