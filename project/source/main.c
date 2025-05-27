#include "parser.h"

#include "u_strings.h"

#include <stdlib.h>

//todo:
//Improve safety / checking for large numbers
//? using __builtin_add_overflow for for overflow checking
//? errno
//Float support
//? Arbitrary percision https://stackoverflow.com/questions/1218149/arbitrary-precision-arithmetic-explanation || GMP if lazy

//Currently running out of space on stack for large equations
//ex. ((1456789 + 984321) / 3 - 45678012 + 31415965 - 271828182 + 0000000000000000000000000000023 ^ 2 ^ 3 + 000000000000000020240210) - 8*10^10 + ((1456789 + 984321) / 3 - 45678012 + 31415965 - 271828182 + 0000000000000000000000000000023 ^ 2 ^ 3 + 00001)

//realloc failing in STACK

//Current main implementation taking effectively any input size
int main() {
  char* equation = input("Equation: ");
  parse(equation);
  free(equation);

  return 0;
}