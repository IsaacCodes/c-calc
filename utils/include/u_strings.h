#pragma once

// User Defined
#include <stdio.h>

// Auto Generated
/* ./utils/source/u_strings.c */
char *input(char *input_message);
i32 sized_input(char *dest, size_t size, char *input_message);
void copy(char *src, char *dest, size_t size);
void substring(char *src, char *dest, size_t size, size_t i1, size_t i2);
void repeat_char(char *dest, size_t size, char c, u32 n);
_Bool contains_char(char *str, char chr);
