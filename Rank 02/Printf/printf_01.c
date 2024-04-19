#include <unistd.h>
#include <stdarg.h>

void	put_string(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
	{
		write(1, string, 1);
		(*length)++;
		string++;
	}
	return ;
}
void	put_number(long long int number, int *length, int base)
{
	char	*hex = "0123456789abcdef";

	if (number < 0)
	{
		number = number * -1;
		write(1, "-", 1);
		(*length)++;
	}
	if (number >= base)
		put_number((number / base), length, base);
	(*length)++;
	write(1, &hex[number % base], 1);
	return ;
}

int	ft_printf(const char *format, ...)
{
	int		length;
	va_list pointer;

	length = 0;
	va_start(pointer, format);
	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1 )) == 'd' || (*(format + 1)) == 'x'))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &length);
			else if (*format == 'd')
				put_number((long long int)va_arg(pointer, int), &length, 10);
			else if (*format == 'x')
				put_number((long long int)va_arg(pointer, unsigned int), &length, 16);
		}
		else
		{
			write(1, format, 1);
			length++;
		}
		format++;
	}
	va_end(pointer);
	return (length);
}

int	main(void)
{
	ft_printf("hello world");
	return (0);
}
