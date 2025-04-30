#pragma once

// User Defined
//...

// Auto Generated
/* ./project/source/parser.c */
i32 get_op_priority(char op);
_Bool is_left_associative(char op);
void infix_to_postfix(char *infix_eq, char *postfix_eq, size_t size);
void parse(char *infix_eq);
