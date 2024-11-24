#include <stdarg.h>
#include <unistd.h>

int	put_string(char *string, int length)
{
	if (!string)
		string = "(null)";
	while (*string)
	{
		write(1, string, 1);
		length++;
		string++;
	}
	return (length);
}

int	put_number(long long int number, int length, int base)
{
	char	*hex = "0123456789abcdef";

	if (number < 0)
	{
		number = number * -1;
		write(1, "-", 1);
		length++;
	}
	if (number >= base)
		length = put_number((number / base), length, base);
	write(1, &hex[number % base], 1);
	length++;
	return (length);
}

int	ft_printf(char *format, ...)
{
	int		length;
	va_list	pointer;

	va_start(pointer, format);
	length = 0;
	while (*format)
	{
		if (((*format) == '%') && ((*(format + 1) == 's') || ((*(format + 1)) == 'd') || ((*(format + 1)) == 'x')))
		{
			format++;
			if (*format == 's')
				length = put_string(va_arg(pointer, char *), length);
			else if (*format == 'd')
				length = put_number((long long int)va_arg(pointer, int), length, 10);
			else if (*format == 'x')
				length = put_number((long long int)va_arg(pointer, unsigned int), length, 16);
		}
		else
		{
			length++;
			write(1, format, 1);
		}
		format++;
	}
	va_end(pointer);
	return (length);
}
