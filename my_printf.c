#include <stdarg.h>
#include <stdio.h>
#include "main.h"

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
				case '%':
					putchar('%');
					count++;
					break;
				default:
					/* Handle unsupported specifier */
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

