#include "u_stack.h"
#include "u_constants.h"
#include "u_safe.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//i is defined as the next free slot (== len)
void stack_init(stack* s, size_t item_size) {
  s->i = 0;
  s->item_size = item_size;
  s->chunk_count = 1;
  s->items = not_null(malloc(s->chunk_count * CHUNK_SIZE * sizeof(void*)));
}

//Expands the stack, reallocing more memory
void stack_expand(stack* s) {
  s->chunk_count++;
  s->items = not_null(realloc(s->items, s->chunk_count * CHUNK_SIZE * sizeof(void*)));
}

//Cleans up stack
void stack_free(stack* s) {
  while (!stack_is_empty(s)) stack_remove(s);
  free(s->items);
}

//Returns whether stack is empty
bool stack_is_empty(stack* s) {
  return s->i == 0;
}

//Returns whether stack is full
bool stack_is_full(stack* s) {
  return s->i == s->chunk_count*CHUNK_SIZE;
}

//Moves an item from one stack to another without deallocating
void stack_move(stack* from_s, stack* to_s) {
  void* to_move = stack_get(from_s);
  stack_add(to_s, to_move);
  stack_remove(from_s);
}

//Adds an item to the top of the stack
void stack_add(stack* s, void* item) {
  if (stack_is_full(s)) stack_expand(s);

  //Allocate memory for item
  s->items[s->i] = not_null(malloc(s->item_size));

  memcpy(s->items[s->i], item, s->item_size);
  s->i++;
}

//Removes the item at the top of the stack
void stack_remove(stack* s) {
  if (stack_is_empty(s)) {
    printf("Nothing to remove from stack\n\n");
    abort();
  }

  s->i--;
  //Free the memory allocated for the removed item
  free(s->items[s->i]);
}

//Gets item pointer from the top of the stack, NULL on fail
void* stack_get(stack* s) {
  if (stack_is_empty(s)) {
    printf("Nothing to get from stack\n\n");
    abort();
  }
  return s->items[s->i - 1];
}