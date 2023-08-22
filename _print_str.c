#include "main.h"

/**
 * _print_str - Print a string to stdout
 * @str: The string to be printed
 *
 * Return: Number of characters printed
 */
int _print_str(char *str)
{
    int count = 0;
    while (*str)
    {
        count += _putchar(*str);
        str++;
    }
    return count;
}

