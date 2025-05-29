#include "parser.h"

#include "u_strings.h"

#include <stdlib.h>

//todo:
//Improve safety / checking for large numbers
//? using __builtin_add_overflow for for overflow checking
//? errno
//Float support
//? Arbitrary percision https://stackoverflow.com/questions/1218149/arbitrary-precision-arithmetic-explanation || GMP if lazy


//Current main implementation taking effectively any input size
int main() {
  char* equation = input("Equation: ");
  parse(equation);
  free(equation);

  return 0;
}