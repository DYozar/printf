#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				printed_chars += buff_ind;
			}
			else
			{
				printed_chars++;
			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			i++; // Skip the '%'

			if (format[i] == '\0')
				return (-1); // Incomplete format specifier

			if (format[i] == '%')
			{
				buffer[buff_ind++] = '%';
				if (buff_ind == BUFF_SIZE)
				{
					print_buffer(buffer, &buff_ind);
					printed_chars += buff_ind;
				}
				else
				{
					printed_chars++;
				}
			}
			else if (format[i] == 'c')
			{
				// Retrieve the argument of type int
				int c = va_arg(list, int);
				buffer[buff_ind++] = (char)c;
				if (buff_ind == BUFF_SIZE)
				{
					print_buffer(buffer, &buff_ind);
					printed_chars += buff_ind;
				}
				else
				{
					printed_chars++;
				}
			}
			else if (format[i] == 's')
			{
				// Retrieve the argument of type char*
				char *str = va_arg(list, char*);
				int j;

				if (str == NULL)
					str = "(null)";

				for (j = 0; str[j] != '\0'; j++)
				{
					buffer[buff_ind++] = str[j];
					if (buff_ind == BUFF_SIZE)
					{
						print_buffer(buffer, &buff_ind);
						printed_chars += buff_ind;
					}
					else
					{
						printed_chars++;
					}
				}
			}
			else
			{
				// Invalid format specifier
				buffer[buff_ind++] = '%';
				buffer[buff_ind++] = format[i];
				if (buff_ind == BUFF_SIZE)
				{
					print_buffer(buffer, &buff_ind);
					printed_chars += buff_ind;
				}
				else
				{
					printed_chars += 2;
				}
			}
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}
