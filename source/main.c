#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "inums.h"
#include "istrings.h"

#include "parser.h"

//Consider generalizing to not just i64 or using __builtin_add_overflow
i64 add(i64 a, i64 b) {
  if ((b > 0 && a > INT64_MAX - b) || (b < 0 && a < INT64_MIN - b)) {
    printf("Your numbers are too big for C's tiny brain\n");
    exit(1);
  }

  return a + b;
}

//Consider error checking for > max i64 on conversion as well as proper buffer sizes
int main(void) {

  char num_str1[20];
  printf("Number 1: ");
  input(num_str1, sizeof(num_str1));
  i64 num1 = strtol(num_str1, NULL, 10);

  char num_str2[20];
  printf("Number 2: ");
  input(num_str2, sizeof(num_str2));
  i64 num2 = strtol(num_str2, NULL, 10);

  char equation[100];
  snprintf(equation, sizeof(equation), "%ld + %ld = %ld", num1, num2, add(num1, num2));

  parse(equation);

  return 0;
}