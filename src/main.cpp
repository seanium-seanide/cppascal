#include "main.h"

#include <iostream>
#include <string>
#include "Interpreter.h"

int main()
{
  std::string input;

  while (std::cin >> input)
  {
    if (input == "")
    {
      continue;
    }

    Interpreter interpreter(input);

    std::string result = interpreter.expr();
    std::cout << result;
  }

  return 0;
}
