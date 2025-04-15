#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "inums.h"
#include "istrings.h"

#include "parser.h"

int main(void) {

  char number_str[20];
  printf("Enter a number: ");
  input(number_str, sizeof(number_str), "yo");

  char equation[50];
  snprintf(equation, sizeof(equation), "%s + %s = %s", number_str, "1", "idk");

  parse(equation);

  return 0;
}