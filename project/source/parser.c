#include "u_strings.h"
#include "u_stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define NUMBERS "0123456789"
#define OPERATORS "^*/+-"


i32 get_op_priority(char op) {
  if (contains_char("^", op)) return 2;
  if (contains_char("*/", op)) return 1;
  else return 0;
}

bool is_left_associative(char op) {
  return op != '^';
}

//Converts a string representing an infix equation to a postfix one
void infix_to_postfix(char* infix_eq, char* postfix_eq, size_t size) {

  //Initialization
  stack output_stack;
  stack_init(&output_stack, sizeof(char));
  stack operator_stack;
  stack_init(&operator_stack, sizeof(char));

  char* chr = infix_eq;
  bool last_chr_was_operator = true;

  //Loops through and processes infix_eq
  while (*chr != '\0') {

    if (*chr == '(') {
      last_chr_was_operator = true;
      stack_add(&operator_stack, chr);
    }

    else if (*chr == ')') {
      last_chr_was_operator = false;
      while (*(char*) stack_get(&operator_stack) != '(') stack_move(&operator_stack, &output_stack);
      stack_remove(&operator_stack);
    }

    else if (contains_char(NUMBERS, *chr) || (last_chr_was_operator && *chr == '-')) {
      last_chr_was_operator = false;
      if(*chr == '-') {
        stack_add(&output_stack, &(char){'~'});
        chr++;
      }

      while (contains_char(NUMBERS, *chr)) {
        stack_add(&output_stack, chr);
        chr++;
      }

      chr--;
      stack_add(&output_stack, &(char){'#'});
    }

    else if (contains_char(OPERATORS, *chr)) {
      last_chr_was_operator = true;
      
      char to_move;
      while (true) {
        if (stack_is_empty(&operator_stack)) break;
        to_move = *(char*) stack_get(&operator_stack);
        if (!contains_char(OPERATORS, to_move)) break;

        i32 to_move_priority = get_op_priority(to_move);
        i32 chr_priority = get_op_priority(*chr);
        if(to_move_priority <= chr_priority && (!is_left_associative(*chr) || to_move_priority != chr_priority)) break;

        stack_move(&operator_stack, &output_stack);
      }

      stack_add(&operator_stack, chr);
    }

    else if (*chr != ' ') {
      printf("Invalid character '%c' entered\n\n", *chr);
      abort();
    }

    chr++;
  }

  //Moves over stragglers from operator stack
  char to_move;
  while (true) {
    if (stack_is_empty(&operator_stack)) break;

    to_move = *(char*) stack_get(&operator_stack);
    if (to_move == '(') {
      printf("Mismatched parenthesis detected\n");
      abort();
    }

    stack_move(&operator_stack, &output_stack);
  }

  //Copies char stack into postfix string
  i32 len = (output_stack.i < (i32) size - 1) ? output_stack.i : (i32) size - 1;
  for (i32 j = 0; j < len; j++) postfix_eq[j] = *(char*) (output_stack.items[j]);
  postfix_eq[len] = '\0';

  //Clean up
  stack_free(&operator_stack);
  stack_free(&output_stack);
}

//Evaluates a postfix string equation
i64 eval_postfix(char* postfix_eq) {

  stack value_stack;
  stack_init(&value_stack, sizeof(i64));

  char* chr = postfix_eq;

  while (*chr != '\0') {
    if (contains_char(NUMBERS, *chr) || *chr == '~') {
      if(*chr == '~') *chr = '-';

      i64 number = strtol(chr, NULL, 10);
      stack_add(&value_stack, &number);

      chr = strchr(chr, '#');
    }
    if (contains_char(OPERATORS, *chr)) {
      i64 num1 = *(i64*) stack_get(&value_stack);
      stack_remove(&value_stack);
      i64 num2 = *(i64*) stack_get(&value_stack);
      stack_remove(&value_stack);

      i64 res;
      switch (*chr) {
        case '^':
          res = pow(num2, num1);
          break;
        case '*':
          res = num2 * num1;
          break;
        case '/':
          res = num2 / num1;
          break;
        case '+':
          res = num2 + num1;
          break;
        case '-':
          res = num2 - num1;
          break;
      }

      stack_add(&value_stack, &res);
    }

    chr++;
  }

  i64 ans = *(i64*) stack_get(&value_stack);
  stack_remove(&value_stack);
  if (!stack_is_empty(&value_stack)) {
    printf("Invalid equation. Multiple items left on value stack\n\n");
    abort();
  }

  stack_free(&value_stack);

  return ans;
}

//Parses user input and outputs stuff
void parse(char* infix_eq) {
  char postfix_eq[2*strlen(infix_eq)];
  infix_to_postfix(infix_eq, postfix_eq, sizeof(postfix_eq));

  //debug: printf("Postfix: %s\n", postfix_eq);

  i64 ans = eval_postfix(postfix_eq);

  printf("The answer to your equation is %ld\n", ans);
}