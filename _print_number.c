#include "main.h"

/**
 * _print_number - Print an integer to stdout
 * @num: The integer to be printed
 *
 * Return: Number of characters printed
 */
int _print_number(int num)
{
    int count = 0;
    if (num < 0)
    {
        count += _putchar('-');
        num = -num;
    }
    if (num / 10)
        count += _print_number(num / 10);
    count += _putchar('0' + num % 10);
    return count;
}

