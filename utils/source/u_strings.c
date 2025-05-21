#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "u_safe.h"
#include "u_nums.h"

//Gets user input, dynamically allocating space. Requires freeing but also can accomodate (effectively) any size of input
char* input(char* input_message) {

  if (input_message) printf("%s", input_message);
  fflush(stdout);

  const i32 chunk_size = 100;
  i32 chunk_count = 1;
  char* dest = not_null(malloc(chunk_size));

  fgets(dest, chunk_size, stdin);

  while((dest[strlen(dest) - 1]) != '\n') {
    char continued_string[100];
    fgets(continued_string, chunk_size, stdin);

    chunk_count++;
    dest = not_null(realloc(dest, chunk_count*chunk_size));
    strcat(dest, continued_string);
  }

  dest[strcspn(dest, "\n")] = '\0';
  return dest;
}

//Safely gets user input, discarding overflow and returning overflow amount
i32 sized_input(char* dest, size_t size, char* input_message) {

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