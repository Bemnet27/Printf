#ifndef _MAIN_H
#define _MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
int _charprintf(int holder)
void _strprintf(char *str)
int _intprintf(int holder, int base_val)
int _printf(const char *format, ...);
#endif
