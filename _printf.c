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
const char *ptr = format;
va_list args;
int count = 0;

va_start(args, format);

while (*ptr != '\0')
	{
	if (*ptr == '%')
	{
		ptr++;

		if (*ptr == 'c')
		{
			char ch = va_arg(args, int);

			putchar(ch);
			count++;
		}
		else if (*ptr == 's')
		{
			char *str = va_arg(args, char*);

			while (*str != '\0')
			{
				while (*str != '\0')
				{
					putchar(*str);
					str++;
					count;
				}
			}
			else if (*ptr == 'd' || *ptr == 'i')
			{
				int num = va_arg(args, int);

				printf("%d", num);
				count++;
			}
			else if (*ptr == '%')
{
putchar('%');
count++;
}
}
else
{
putchar(*ptr);
count++;
}
ptr++;
}
va_end(args);

	return (count);
}
