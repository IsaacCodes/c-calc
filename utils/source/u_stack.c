#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "u_stack.h"

//Initializes the stack struct with 0's
//i is defined as the next free slot
void stack_init(stack* s, size_t item_size) {
  s->i = 0;
  s->item_size = item_size;
  memset(s->items, 0, sizeof(s->items));
}

//Cleans up stack
void stack_free(stack* s) {
  while (!stack_is_empty(s)) {
    stack_remove(s);
  }
}

//Returns whether stack is empty
bool stack_is_empty(stack* s) {
  return s->i == 0;
}

//Returns whether stack is full
bool stack_is_full(stack* s) {
  return s->i == STACK_MAX;
}

//Adds an item to the top of the stack
void stack_add(stack* s, void* item) {
  if (stack_is_full(s)) {
    printf("Out of space on stack\n\n");
    exit(1);
  }

  //Allocate memory for item
  s->items[s->i] = malloc(s->item_size);
  if (s->items[s->i] == NULL) {
    printf("Memory allocation failed\n\n");
    exit(1);
  }

  memcpy(s->items[s->i], item, s->item_size);
  s->i++;
}

//Removes the item at the top of the stack
void stack_remove(stack* s) {
  if (stack_is_empty(s)) {
    printf("Nothing to remove from stack\n\n");
    exit(1);
  }

  s->i--;
  //Free the memory allocated for the removed item
  free(s->items[s->i]);
  s->items[s->i] = NULL;
}

//Gets item pointer from the top of the stack, NULL on fail
void* stack_get(stack* s) {
  if (stack_is_empty(s)) {
    printf("Nothing to get from stack\n\n");
    exit(1);
  }
  return s->items[s->i - 1];
}