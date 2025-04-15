#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "inums.h"
#include "parser.h"

int main(void) {

  bool boo = true;
  i32 num = pow(2, 30);

  char output[50];
  snprintf(output, sizeof(output), "%d + %ld = %ld", boo, num, num + (i32) boo);

  parse(output);

  return 0;
}