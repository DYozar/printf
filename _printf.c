#include <stdio.h>
#include <stdarg.h> // for variadic arguments

/**
 * _printf - Custom implementation of printf function
 * @format: A format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	char ch;
	
	/* Start variadic arguments */
	va_start(args, format);

	/* Loop through the format string */
	for (int i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			printed_chars++;
			continue;
		}

		i++;

		/* Handle conversion specifier */
		ch = format[i];
		switch (ch)
		{
			case 'c':
				/* Retrieve the next argument and print as a character */
				putchar(va_arg(args, int));
				printed_chars++;
				break;

			case 's':
				/* Retrieve the next argument and print as a string */
				{
					char *str = va_arg(args, char *);
					if (!str) // if argument is NULL, print "(null)"
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
				/* Print a literal '%' character */
				putchar('%');
				printed_chars++;
				break;

			default:
				/* Print unsupported conversion specifiers as is */
				putchar('%');
				putchar(ch);
				printed_chars += 2;
				break;
		}
	}

	/* Clean up variadic arguments */
	va_end(args);

	return printed_chars;
}

