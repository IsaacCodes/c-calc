#pragma once

// User Defined
#include "stddef.h"
#include "u_nums.h"

// Auto Generated
/* ./project/source/parser.c */
i32 get_op_priority(char op);
_Bool is_left_associative(char op);
void infix_to_postfix(char *infix_eq, char *postfix_eq, size_t size);
i64 eval_postfix(char *postfix_eq);
void parse(char *infix_eq);
