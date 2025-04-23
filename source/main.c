#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "inums.h"
#include "istrings.h"

#include "parser.h"

//Also check out https://stackoverflow.com/questions/1815367/catch-and-compute-overflow-during-multiplication-of-two-large-integers

//Or maybe https://stackoverflow.com/questions/3340511/what-is-the-simplest-way-of-implementing-bigint-in-c

//Consider generalizing to not just i64 or using __builtin_add_overflow
i64 add(i64 a, i64 b) {
  if ((b > 0 && a > INT64_MAX - b) || (b < 0 && a < INT64_MIN - b)) {
    printf("Your numbers are too big for C's tiny brain\n");
    exit(1);
  }

  return a + b;
}

//Consider error checking for > max i64 on conversion as well as proper buffer sizes
//Research errno
int main(void) {

  char num_str1[20];
  input(num_str1, sizeof(num_str1), "Number 1: ", "Input truncated");
  i64 num1 = strtol(num_str1, NULL, 10);

  char num_str2[20];
  input(num_str2, sizeof(num_str2), "Number 2: ", "Input truncated");
  i64 num2 = strtol(num_str2, NULL, 10);

  char equation[100];
  snprintf(equation, sizeof(equation), "%ld + %ld = %ld", num1, num2, add(num1, num2));

  parse(equation);

  return 0;
}