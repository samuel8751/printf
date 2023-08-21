#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
const char *ptr = format;
int charCount = 0;

va_list args;
va_start(args, format);

while (*ptr != '\0')
{
if (*ptr == '%')
{
ptr++; /* Move past the '%'*/

if (*ptr == 'c')
{
char ch = va_arg(args, int);
putchar(ch);
charCount++;
}
else if (*ptr == 's')
{
char *str = va_arg(args, char*);
while (*str != '\0')
{
putchar(*str);
str++;
charCount++;
}
}
else if (*ptr == '%')
{
putchar('%');
charCount++;
}
}
else
{
putchar(*ptr);
charCount++;
}
ptr++;
}
va_end(args);

return (charCount);
}

int main()
{
_printf("Character: %c\n", 'A');
_printf("String: %s\n", "Hello, world!");
_printf("Literal percentage sign: %%\n");

return (0);
}
