#include <stdio.h>
#include <string.h>

void input(char* dest, size_t size) {
  fgets(dest, size, stdin);
  dest[strcspn(dest, "\n")] = '\0';
}

void copy(char* src, char* dest, size_t size) {
  snprintf(dest, size, "%s", src);
}