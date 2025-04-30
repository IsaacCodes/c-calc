#include <stdio.h>
#include <stdbool.h>

#include "u_stack.h"

void stack_init(stack* s) {
  s->i = 0;
}

bool stack_is_empty(stack* s) {
  return s->i == 0;
}

bool stack_is_full(stack* s) {
  return s->i == STACK_MAX-1;
}

char stack_get(stack* s) {
  return s->items[s->i];
}

bool stack_add(stack* s, char item) {

  if (stack_is_full(s)) {
    printf("Out of space on stack\n");
    return false;
  }

  s->items[s->i] = item;
  s->i++;
  return true;
}

bool stack_remove(stack* s) {

  if (stack_is_empty(s)) {
    printf("Nothing to remove from stack\n");
    return false;
  }

  s->items[s->i] = '\0';
  s->i--;
  return true;
}