#include "main.h"
/**
 * _printf - custom printf function handling c and s
 * @format: format string
 *
 * Return: number of character
 */

int _charprintf(int holder)
{
	return write(1, &holder, 1);
}

void _strprintf(char *str)
{
	int n = strlen(str);
	int i;

	for (i = 0; (i < n) && (*str != '\0'); i++)
	{
		_charprintf((int)*str);
		++str;
	}
}

int _intprintf(int holder, int base_val)
{
	int counter;

	char hex_values[] = "0123456789abcdef";
	counter = 0;
	if (holder < 0)
	{
		_charprintf('-');
		counter = _intprintf(((holder*holder)/2), base_val) + 1;
		return counter;
	}
	else if (holder < base_val)
	{
		counter++;
		_charprintf(hex_values[holder]);
		return counter;
	}
	else
	{
		counter = _intprintf(holder / base_val, base_val);
		return counter + _intprintf(holder % base_val, base_val);
	}
}

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
					counter += _charprintf(holder);
					break;
				case 's':
					str = va_arg(args, char*);
					_strprintf(str);
					counter += strlen(str);
					break;
				case '%':
					write(1, format, 1);
					counter++;
					break;
				case 'd':
					holder = va_arg(args, int);
					counter += _intprintf(holder, 10);
					break;
				case 'i':
					holder = va_arg(args, int);
					counter += _intprintf(holder, 10);
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
