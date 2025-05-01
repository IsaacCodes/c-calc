#pragma once

// User Defined
#include <stdio.h>

// Auto Generated
/* ./utils/source/u_strings.c */
i32 input(char *dest, size_t size, char *input_message);
void copy(char *src, char *dest, size_t size);
void repeat_char(char *dest, size_t size, char c, u32 n);
_Bool contains_char(char *str, char chr);
