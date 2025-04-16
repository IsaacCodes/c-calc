#include <stdio.h>
#include <string.h>

void input(char* dest, size_t size) {
  fgets(dest, size, stdin);

  if (dest[strlen(dest) - 1] != '\n') {
    char chr;
    while ((chr = getchar()) != '\n' && chr != EOF);
  }

  dest[strcspn(dest, "\n")] = '\0';
}

void copy(char* src, char* dest, size_t size) {
  snprintf(dest, size, "%s", src);
}