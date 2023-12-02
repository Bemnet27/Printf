#include "main.h"
/**
 * _printf - custom printf function handling c and s
 * @format: format string
 *
 * Return: number of character
 */
int _printf(const char *format, ...)
{
	char holder;
	int counter;
	char *str;

	va_list args;

	va_start(args, format);

	counter = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					holder = va_arg(args, int);
					write(1, &holder, 1);
					counter++;
					break;
				case 's':
					str = va_arg(args, char*);
					write(1, str, strlen(str));
					counter++;
					break;
				case '%':
					write(1, format, 1);
					counter++;
					break;
				default:
					write(1, format, 1);
					counter++;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			counter++;
		}
		format++;
	}
	va_end(args);
	return (counter);
}
