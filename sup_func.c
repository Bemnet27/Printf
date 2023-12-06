#include "main.h"
/**
 * _charprintf - prints out an int using write command
 * @holder: operand holding what will be printed out
 *
 * Return: number of characters printed out
 */
int _charprintf(int holder)
{
	return (write(1, &holder, 1));
}

/**
 * _putchar - prints out a char using write command
 * @c : operand holding the char to be printed
 *
 * Return: number of characters printed out
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strprintf - prints out a string
 * @str : pointer to the string
 *
 * Return: number of characters printed out
 */
int _strprintf(char *str)
{
	int n = strlen(str);
	int i;

	for (i = 0; (i < n) && (*str != '\0'); i++)
	{
		_charprintf((int)*str);
		++str;
	}
	return (n);
}

/**
 * get_base_val - gets the base value depending on the case character
 * @case_char : operand holding the case character from _intprintf
 *
 * Return: the base value of the case recieved
 */
int get_base_val(char case_char)
{
	int base_val;

	if (case_char == 'X' || case_char == 'x')
		base_val = 16;
	else if (case_char == 'o')
		base_val = 8;
	else
		base_val = 10;
	return (base_val);
}

/**
 * _intprintf - prints out the value of numbers
 * @digit_holder : operand holding the value of the passed digit
 * @case_char : operand holding the value of the case char
 *
 * Return: Number of characters printed out
 */
int _intprintf(long digit_holder, char case_char)
{
	int counter;
	long abs;
	char hex_values_lo[] = "0123456789abcdef";
	char hex_values_up[] = "0123456789ABCDEF";
	char *hex_values = (case_char == 'X') ? hex_values_up: hex_values_lo;
	int base_val = get_base_val(case_char);

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
			return (counter);
		}
		else
		{
			counter = _intprintf(abs / base_val, case_char);
			return (counter + _intprintf(abs % base_val, case_char));
		}
	}
	else if (digit_holder < base_val)
	{
		counter++;
		_putchar(hex_values[digit_holder]);
		return (counter);
	}
	else
	{
		counter = _intprintf(digit_holder / base_val, case_char);
	return (counter + _intprintf(digit_holder % base_val, case_char));
	}
}
