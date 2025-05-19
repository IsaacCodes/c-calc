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
//? big int https://stackoverflow.com/questions/3340511/what-is-the-simplest-way-of-implementing-bigint-in-c
//? using __builtin_add_overflow for for overflow checking
//? errno
//Float support

int main() {
  char equation[EQUATION_INFIX_MAX];
  char input_message[] = "Equation: ";
  char overflow_message[] = "Trimming";

  i32 overflow = input(equation, sizeof(equation), input_message);
  if (overflow) {
    i32 space_count = -strlen(overflow_message)+strlen(input_message)+strlen(equation);
    char arrows[overflow + 1];
    repeat_char(arrows, sizeof(arrows), '^', overflow);
    
    printf("%s%*s%s\n\n", overflow_message, space_count, "", arrows);
  }
  parse(equation);

  return 0;
}