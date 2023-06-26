#include <stdio.h>
#include <stdarg.h>

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

            // Handle the conversion specifier
            switch (*format)
            {
                case 'c':
                {
                    // Fetch the character argument
                    int c = va_arg(args, int);
                    // Print the character
                    putchar(c);
                    count++;
                    break;
                }
                case 's':
                {
                    // Fetch the string argument
                    const char *str = va_arg(args, const char *);
                    // Print the string
                    while (*str)
                    {
                        putchar(*str);
                        str++;
                        count++;
                    }
                    break;
                }
                case '%':
                {
                    // Print a literal %
                    putchar('%');
                    count++;
                    break;
                }
                default:
                    // For any other character, just print it as is
                    putchar(*format);
                    count++;
                    break;
            }
        }
        else
        {
            // Print regular characters
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
