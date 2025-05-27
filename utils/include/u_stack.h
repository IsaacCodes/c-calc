#pragma once

// User Defined
#include "u_nums.h"
#include <stddef.h>

typedef struct {
  void** items;
  i32 chunk_count;
  size_t item_size;
  i32 i;
} stack;

// Auto Generated
/* ./utils/source/u_stack.c */
void stack_init(stack *s, size_t item_size);
void stack_expand(stack *s);
void stack_free(stack *s);
_Bool stack_is_empty(stack *s);
_Bool stack_is_full(stack *s);
void stack_move(stack *from_s, stack *to_s);
void stack_add(stack *s, void *item);
void stack_remove(stack *s);
void *stack_get(stack *s);
