#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	output_str(const char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '%' && str[counter] != '\0')
	{
		ft_putchar_fd(str[counter], 1);
		counter++;
	}
	return (counter + 1);
}

int	final_function(const char *str, int counter3, int counter2, int *counter)
{
	*counter += output_str(str + *counter);
	return (*counter + counter3 - (counter2 * 2) - 1);
}

int	counter_percentages(const char *str)
{
	int	counter;
	int	counter_percentage;

	counter = 0;
	counter_percentage = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] == '%')
		{
			counter_percentage++;
		}
		counter++;
	}
	return (counter_percentage);
}

void	set_to_zero(int *c1, int *c2, int *c3)
{
	*c1 = 0;
	*c2 = 0;
	*c3 = 0;
}

int	ft_printf(const char *format, ...)
{
	int		counter2;
	int		counter;
	int		counter3;
	va_list	args;

	va_start(args, format);
	set_to_zero(&counter, &counter2, &counter3);
	while (counter2 < counter_percentages(format))
	{
		counter += output_str(format + counter);
		if (format[counter] == 'd' || format[counter] == 'i')
			int_mode(va_arg(args, int), &counter3, &counter2, &counter);
		else if (format[counter] == 'u')
			unsigned_int_mode(va_arg(args, unsigned int), &counter3, &counter2, &counter);
		else if (format[counter] == 'x' || format[counter] == 'X')
			hexadecimal_mode(va_arg(args, unsigned int), &counter3, &counter2, &counter);
		else if (format[counter] == 's')
			string_mode(va_arg(args, char *), &counter3, &counter2, &counter);
		else if (format[counter] == 'c' || format[counter] == '%')
			char_mode(va_arg(args, int), &counter3, &counter2, &counter);
		else if (format[counter] == 'p')
			pointer_mode(va_arg(args, void *), &counter3, &counter2, &counter);
		return (0);
	}
	va_end(args);
	return (final_function(format, counter3, counter2, &counter));
}
