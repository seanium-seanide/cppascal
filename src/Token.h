#ifndef CLASS_TOKEN_H
#define CLASS_TOKEN_H

#include <ostream>
#include <string>

#include "token_constants.h"

class Token
{
public:

  Token(std::string type, int value);
  ~Token();

  std::string getType() { return m_type; }

  /**
   * @brief Overloaded stream output operator to print string representation
   *        of the Token instance.
   *
   * @param[in] out   Output stream onto which string will be written.
   * @param[in] token Token whose string representation will be written onto the output stream.
   *
   * @return out in its state after having been written to.
   */
  friend std::ostream &operator<<(std::ostream &out, const Token &token);

private:

  std::string m_type;
  int         m_value;

  /**
   * @brief Return string representation of the Token instance.
   */
  std::string to_string() const;
};

#endif
