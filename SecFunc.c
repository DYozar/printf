#include "main.h"
#include <unistd.h>
#include <stdlib.h>

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
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
char *str = int_to_str(num);
if (str == NULL)
return -1;  // Handle error
int len = 0;
while (str[len])
{
write(1, &str[len], 1);
len++;
count++;
}
free(str);
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
