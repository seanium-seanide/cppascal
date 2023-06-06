#ifndef CLASS_INTERPRETER_H
#define CLASS_INTERPRETER_H

#include <string>
#include <ostream>

class Interpreter
{
public:

  Interpreter();
  Interpreter(std::string text);
  ~Interpreter();

  std::string expr() const;

private:

};

#endif
