#include "main.h"
#include <unistd.h>

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
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
if (*format == '\0')
break;
else if (*format == 'c')
{
char c = va_arg(args, int);
write(1, &c, 1);
count++;
}
else if (*format == 's')
{
char *str = va_arg(args, char *);
int len = 0;
while (str[len])
{
write(1, &str[len], 1);
len++;
count++;
}
}
else if (*format == '%')
{
write(1, "%", 1);
count++;
}
else
{
write(1, "%", 1);
write(1, format, 1);
count += 2;
}
}
else
{
write(1, format, 1);
count++;
}
format++;
}

va_end(args);

return count;
}
