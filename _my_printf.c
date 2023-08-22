#include <stdio.h>
#include <stdarg.h>
#include "main.h"

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
count += _print_str(va_arg(args, char));
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

{
count += _putchar(*format);
}
format++;
}

va_end(args);
return (count);
}

int _putchar(char c)
{
return (write(1, &c, 1));
}

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

int _print_int(int num)
{
int count = 0;
if (num < 0)
{
count += _putchar('-');
num = -num;
}
if (num == 0)
{
count += _putchar('0');
return (count);
}
int reversed = 0;
/*int reversed = 0;*/
/*int original_num = num;*/

while (num > 0)
{
reversed = reversed * 10 + num % 10;
num /= 10;
}

while (reversed > 0)
{
count += _putchar('0' + reversed % 10);
reversed /= 10;
}

return (count);
}
