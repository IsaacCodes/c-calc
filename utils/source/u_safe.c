#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

//Asserts that a location in memory isn't null
void* not_null(void* memory) {
  if (memory == NULL) {
    printf("Memory allocation failed\n\n");
    exit(1);
  }

  return memory;
}