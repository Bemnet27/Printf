#ifndef _MAIN_H
#define _MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int _charprintf(int holder);
int _putchar(char c);
int _strprintf(char *str);
int get_base_val(char case_char);
int _intprintf(long digit_holder, char case_char);
int _printf(const char *format, ...);
#endif
