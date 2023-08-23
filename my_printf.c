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
 * _printf - Custom printf implementation
 * @format: Format string
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
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					count += printf("%s", va_arg(args, const char *));
					break;
				case 'd':
				case 'i':
					count += printf("%d", va_arg(args, int));
					break;
				case 'b':
					print_binary(va_arg(args, unsigned int), &count);
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}

