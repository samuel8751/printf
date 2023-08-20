#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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
	return count;
}

/**
 * _putchar - Print a single character to stdout
 * @c: The character to be printed
 *
 * Return: 1 (success)
 */
int _putchar(char c)
{
	return write(1, &c, 1);
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
	return count;
}

