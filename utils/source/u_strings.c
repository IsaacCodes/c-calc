#include "u_strings.h"
#include "u_constants.h"
#include "u_safe.h"
#include "u_nums.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//Gets user input, dynamically allocating space. Requires freeing but also can accommodate (effectively) any size of input
char* input(char* input_message) {
  if (input_message) printf("%s", input_message);
  fflush(stdout);

  char* dest = not_null(malloc(CHUNK_SIZE));
  dest[0] = '\0';
  char buf[CHUNK_SIZE];

  while(true) {
    if (!fgets(buf, CHUNK_SIZE, stdin)) break;

    size_t dest_len = strlen(dest);
    size_t buf_len = strlen(buf);

    dest = not_null(realloc(dest, dest_len + buf_len + 1));
    copy(buf, dest + dest_len, buf_len + 1);

    if (buf[buf_len - 1] == '\n') break;
  }

  dest[strcspn(dest, "\n")] = '\0';
  return dest;
}

//Safely gets user input, discarding overflow and returning overflow amount
i32 sized_input(char* dest, size_t size, char* input_message) {
  if (input_message) printf("%s", input_message);
  fflush(stdout);

  fgets(dest, size, stdin);
  
  i32 overflow = 0;
  if (dest[strlen(dest) - 1] != '\n') {
    char chr;
    while ((chr = getchar()) != '\n' && chr != EOF) overflow++;
  }

  dest[strcspn(dest, "\n")] = '\0';
  return overflow;
}

//Safely copies a whole string
void copy(char* src, char* dest, size_t size) {
  size_t i;
  for (i = 0; i < size - 1 && src[i] != '\0'; i++) dest[i] = src[i];
  dest[i] = '\0';
}

//Returns whether a non-null chr is in a str
bool contains_char(char* str, char chr) {
  return chr != '\0' && strchr(str, chr) != NULL;
}