#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _print_str(char *str);
void print_binary(unsigned int n, int *count);

#endif /* MAIN_H */
