#include "main.h"
/**
 * _printf - custom printf function handling c, s, d and i
 * @format: format string
 *
 * Return: number of character
 */

int _charprintf(int holder)
{
	
	return write(1, &holder, 1);
}

int _putchar(char c)
{
	return write(1, &c, 1);	
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

int _intprintf(int digit_holder, int base_val)
{
	int counter;
	int abs;

	char hex_values[] = "0123456789abcdef";
	counter = 0;
	if (digit_holder < 0)
	{
		_putchar('-');
		counter++;
		abs = labs(digit_holder);
		if (abs < base_val)
        	{
			counter++;
			_putchar(hex_values[abs]);
			return counter;
		}
		else
		{
			counter = _intprintf(abs / base_val, base_val);
			return counter + _intprintf(abs % base_val, base_val);
		}
	}
	else if (digit_holder < base_val)
	{
		counter++;
		_putchar(hex_values[digit_holder]);
		return counter;
	}
	else
	{
		counter = _intprintf(digit_holder / base_val, base_val);
		return counter + _intprintf(digit_holder % base_val, base_val);
	}
}

int _printf(const char *format, ...)
{
	char holder;
	int counter;
	char *str;
	int digit_holder;

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
				case 'i':
					digit_holder = va_arg(args, int);
                                        counter += _intprintf(digit_holder, 10);
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
