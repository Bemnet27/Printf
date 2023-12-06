#include "main.h"
/**
 * _printf - custom printf function handling c, s, d and i
 * @format: format string
 *
 * Return: number of character
 */
int _printf(const char *format, ...)
{
	int counter;
	va_list args;

	va_start(args, format);
	counter = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				counter += _charprintf(va_arg(args, int));
			else if (*format == 's')
				counter += _strprintf(va_arg(args, char*));
			else if (*format == '%')
				counter += write(1, format, 1);
			else if (*format == 'd' || *format == 'i')
				counter += _intprintf(va_arg(args, int), 'i');
			else if (*format == 'o' || *format == 'u')
				counter += _intprintf((long)va_arg(args, unsigned int), *format);
			else if (*format == 'x' || *format == 'X')
				counter += _intprintf((long)va_arg(args, unsigned int), *format);
			else
				counter += write(1, format, 1);
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
