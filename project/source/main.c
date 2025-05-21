#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "u_nums.h"
#include "u_strings.h"

#include "constants.h"
#include "parser.h"

//todo:
//Improve safety / checking for large numbers
//? using __builtin_add_overflow for for overflow checking
//? errno
//Float support
//? Arbitrary percision https://stackoverflow.com/questions/1218149/arbitrary-precision-arithmetic-explanation || GMP if lazy

//Currently running out of space on stack for large equations
//ex. ((1456789 + 984321) / 3 - 45678012 + 31415965 - 271828182 + 0000000000000000000000000000023 ^ 2 ^ 3 + 000000000000000020240210) - 8*10^10 + ((1456789 + 984321) / 3 - 45678012 + 31415965 - 271828182 + 0000000000000000000000000000023 ^ 2 ^ 3 + 00001)

//Current main implementation taking effectively any input size
int main() {
  char* equation = input("Equation: ");
  parse(equation);
  free(equation);

  return 0;
}

//Former implementation of main using sized_input
int old_main() {
  char equation[EQUATION_INFIX_MAX];
  char input_message[] = "Equation: ";
  char overflow_message[] = "Trimming";

  i32 overflow = sized_input(equation, sizeof(equation), input_message);
  if (overflow) {
    i32 space_count = -strlen(overflow_message)+strlen(input_message)+strlen(equation);
    char arrows[overflow + 1];
    repeat_char(arrows, sizeof(arrows), '^', overflow);
    
    printf("%s%*s%s\n\n", overflow_message, space_count, "", arrows);
  }
  parse(equation);

  return 0;
}