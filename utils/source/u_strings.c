#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "u_nums.h"

//Safely gets user input, discarding overflow and returning overflow amount
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

//Safely copies a whole string
void copy(char* src, char* dest, size_t size) {
  strncpy(dest, src, size - 1);
  dest[size - 1] = '\0';
}

//Gets a substring from index i1 (inclusive) to i2 (exclusive)
void substring(char* src, char* dest, size_t size, size_t i1, size_t i2) {
  size_t sub_len = (i2 - i1 - 1 < size - 1) ? i2 - i1 - 1 : size - 1;
  strncpy(dest, src + i1, sub_len);
  dest[sub_len] = '\0';
}

//Repeats a character n times
void repeat_char(char* dest, size_t size, char c, u32 n) {
  if (size-1 < n) n = size-1;
  for (u32 i = 0; i < n; i++) dest[i] = c;
  dest[n] = '\0';
}

//Returns whether a non-null chr is in a str
bool contains_char(char* str, char chr) {
  return chr != '\0' && strchr(str, chr) != NULL;
}