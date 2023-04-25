#include <stdio.h>
#include <stdarg.h> // for variadic arguments

/**
 * _printf - Custom implementation of printf function
 * @format: A format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0; // count of characters printed
	va_list args; // va_list for variadic arguments
	char ch; // to store each character in format string

	/* Start variadic arguments */
	va_start(args, format);

	/* Loop through the format string */
	for (int i = 0; format && format[i]; i++)
	{
		if (format[i] != '%') // if not a conversion specifier
		{
			putchar(format[i]); // print the character
			printed_chars++; // increment printed character count
			continue; // move to next iteration
		}

		i++; // move past '%'

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

