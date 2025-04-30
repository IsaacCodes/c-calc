#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "u_stack.h"
#include "u_strings.h"

#define NUMBERS "0123456789"
#define OPERATORS "^*/+-"


i32 get_op_priority(char op) {
  if (strchr("^", op)) return 2;
  if (strchr("*/", op)) return 1;
  else return 0;
}

bool is_left_associative(char op) {
  return op != '^';
}

void infix_to_postfix(char* infix_eq, char* postfix_eq, size_t size) {

  stack output_stack;
  stack_init(&output_stack);
  stack operator_stack;
  stack_init(&operator_stack);

  char* chr = infix_eq;  

  while (*chr != '\0') {

    if (*chr == '(') {
      assert( stack_add(&operator_stack, '(') );
    }
    else if (*chr == ')') {
      char to_move = stack_get(&operator_stack);

      while (to_move != '(') {
        assert( stack_remove(&operator_stack) );
        assert( stack_add(&output_stack, to_move) );
        to_move = stack_get(&operator_stack);
      }

      assert( stack_remove(&operator_stack) );
    }
    else if (strchr(NUMBERS, *chr)) {
      assert( stack_add(&output_stack, *chr) );
    }
    else if (strchr(OPERATORS, *chr)) {
      char to_move = stack_get(&operator_stack);

      //todo later: make this clean. do while maybe?
      while (strchr(OPERATORS, to_move) 
            && ((get_op_priority(to_move) >= get_op_priority(*chr)) 
            || (is_left_associative(*chr) && get_op_priority(to_move) == get_op_priority(*chr)))) {

        assert( stack_remove(&operator_stack) );
        assert( stack_add(&output_stack, to_move) );

        to_move = stack_get(&operator_stack);
      }
      assert( stack_add(&output_stack, *chr) );
    }
    else if (*chr != ' ') {
      printf("Invalid character entered\n");
      assert( false );
    }

    chr++;
  }

  char to_move;
  while (true) {
    if (stack_is_empty(&operator_stack)) break;

    to_move = stack_get(&operator_stack);
    assert( to_move != '(' );

    assert( stack_remove(&operator_stack) );
    assert( stack_add(&output_stack, to_move) );
  }

  copy(output_stack.items, postfix_eq, size);

}

void parse(char* infix_eq) {

  //todo: standardize these sizes somewhere
  char postfix_eq[100];
  infix_to_postfix(infix_eq, postfix_eq, sizeof(postfix_eq));

  printf("Your equation in postfix is %s\n", postfix_eq);

}