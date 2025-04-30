#pragma once

// User Defined
#include "u_nums.h"

#define STACK_MAX 100
typedef struct {
  char items[STACK_MAX];
  i32 i;
} stack;

// Auto Generated
/* ./utils/source/u_stack.c */
void stack_init(stack *s);
_Bool stack_is_empty(stack *s);
_Bool stack_is_full(stack *s);
char stack_get(stack *s);
_Bool stack_add(stack *s, char item);
_Bool stack_remove(stack *s);
