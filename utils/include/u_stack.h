#pragma once

// User Defined
#include "u_nums.h"
#include "constants.h"

#define STACK_MAX EQUATION_POSTFIX_MAX
typedef struct {
  void* items[STACK_MAX];
  size_t item_size;
  i32 i;
} stack;

// Auto Generated
/* ./utils/source/u_stack.c */
void stack_init(stack *s, size_t item_size);
void stack_free(stack *s);
_Bool stack_is_empty(stack *s);
_Bool stack_is_full(stack *s);
void stack_add(stack *s, void *item);
void stack_remove(stack *s);
void *stack_get(stack *s);
