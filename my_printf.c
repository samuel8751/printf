#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of an unsigned int
 * @n: The number to print in binary
 * @count: Pointer to count variable to update the count
 */
void print_binary(unsigned int n, int *count)
{
	if (n > 1)
		print_binary(n / 2, count);
	*count += putchar('0' + (n % 2));
}

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Arguments to be printed
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _print_str(va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					count += printf("%d", va_arg(args, int));
					break;
				case 'b':
					print_binary(va_arg(args, unsigned int), &count);
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * _putchar - Print a single character to stdout
 * @c: The character to be printed
 *
 * Return: 1 (success)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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
	return (count);
}

