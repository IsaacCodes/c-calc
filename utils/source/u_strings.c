#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "u_nums.h"

i32 input(char* dest, size_t size, char* input_message) {

  i32 overflow = 0;

  if (input_message) printf("%s", input_message);
  fflush(stdout);

  fgets(dest, size, stdin);
  
  if (dest[strlen(dest) - 1] != '\n') {
    char chr;
    while ((chr = getchar()) != '\n' && chr != EOF) overflow++;
  }

  dest[strcspn(dest, "\n")] = '\0';
  return overflow;
}

void copy(char* src, char* dest, size_t size) {
  snprintf(dest, size, "%s", src);
}

void repeat_char(char* dest, size_t size, char c, u32 n) {
  if (size-1 < n) n = size-1;
  for (u32 i = 0; i < n; i++) dest[i] = c;
  dest[n] = '\0';
}

bool contains_char(char* str, char chr) {
  return chr != '\0' && strchr(str, chr) != NULL;
}