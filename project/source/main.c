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
//? big int https://stackoverflow.com/questions/3340511/what-is-the-simplest-way-of-implementing-bigint-in-c
//? using __builtin_add_overflow for addition
//creating other non addition safety operations
//error checking for > max i64 (? errno)
//moving this to another file for better organization

//improve header file organization so includes follow whatever tf the best parctices are supposed to be here

i64 add(i64 a, i64 b) {
  if ((b > 0 && a > INT64_MAX - b) || (b < 0 && a < INT64_MIN - b)) {
    printf("Your numbers are too big for C's tiny brain\n");
    exit(1);
  }

  return a + b;
}

int main(void) {

  //Old addition code
  /*
  char num_str1[20];
  input(num_str1, sizeof(num_str1), "Number 1: ", "Input truncated");
  i64 num1 = strtol(num_str1, NULL, 10);

  char num_str2[20];
  input(num_str2, sizeof(num_str2), "Number 2: ", "Input truncated");
  i64 num2 = strtol(num_str2, NULL, 10);

  snprintf(equation, sizeof(equation), "%ld + %ld = %ld", num1, num2, add(num1, num2));
  */

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