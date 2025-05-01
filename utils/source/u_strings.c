#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void input(char* dest, size_t size, char* input_message, char* overflow_message) {

  if (input_message) printf("%s", input_message);
  fflush(stdout);

  fgets(dest, size, stdin);
  
  if (dest[strlen(dest) - 1] != '\n') {
    char chr;
    while ((chr = getchar()) != '\n' && chr != EOF);
    if (overflow_message) printf("%s\n", overflow_message);
  }

  dest[strcspn(dest, "\n")] = '\0';
}

void copy(char* src, char* dest, size_t size) {
  snprintf(dest, size, "%s", src);
}

bool contains_char(char* str, char chr) {
  return chr != '\0' && strchr(str, chr) != NULL;
}