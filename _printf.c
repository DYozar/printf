#include <stdio.h>
#include <stdarg.h> // for variadic arguments

/**
 * _printf - Custom implementation of printf function
 * @format: A format string
 * Return: The number of characters printed
 */
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    int printed_chars = 0;
    va_list args;
    char ch;

    va_start(args, format);

    for (int i = 0; format && format[i]; i++)
    {
        if (format[i] != '%')
        {
            putchar(format[i]);
            printed_chars++;
            continue;
        }

        i++;

        ch = format[i];
        switch (ch)
        {
            case 'c':
                putchar(va_arg(args, int));
                printed_chars++;
                break;

            case 's':
                {
                    char *str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    while (*str)
                    {
                        putchar(*str);
                        printed_chars++;
                        str++;
                    }
                }
                break;

            case '%':
                putchar('%');
                printed_chars++;
                break;

            default:
                putchar('%');
                putchar(ch);
                printed_chars += 2;
                break;
        }
    }

    va_end(args);

    return printed_chars;
}
