#include "libft/libft.h"
#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>
#include <stdint.h>

void	string_mode(char *str, int *counter, int *counter3, int *counter4)
{
	int	counter2;

	ft_putstr_fd(str, 1);
	counter2 = 0;
	while (*(str + counter2) != '\0')
	{
		counter2++;
	}
	*counter += counter2;
	*counter3 += 1;
	*counter4 += 1;
}

void	char_mode(int c, int *counter, int *counter3, int *counter4)
{
	char	character;

	character = (char)c;
	ft_putchar_fd(character, 1);
	*counter = *counter + 1;
	*counter3 += 1;
	*counter4 += 1;
}

void	int_mode(int integer, int *counter, int *counter3, int *counter4)
{
	char	*str;
	int		counter2;

	str = ft_itoa(integer);
	ft_putstr_fd(str, 1);
	counter2 = 0;
	while (*(str + counter2) != '\0')
	{
		counter2++;
	}
	*counter += counter2;
	*counter3 += 1;
	*counter4 += 1;
}

void	unsigned_int_mode(unsigned int integer, int *counter,
int *counter3, int *counter4)
{
	char	*str;
	int		counter2;

	str = ft_itoa(integer);
	ft_putstr_fd(str, 1);
	counter2 = 0;
	while (*(str + counter2) != '\0')
	{
		counter2++;
	}
	*counter += counter2;
	*counter3 += 1;
	*counter4 += 1;
}

void	decimal_to_hex(uintptr_t memory_address, int *counter)
{
	char *hexadecimal_list;
	int c_index;
	size_t counter2;
	char *str;

	str = (char *)malloc(17*sizeof(char));
	hexadecimal_list = "0123456789abcdef";
	counter2 = 0;
	while(memory_address / 16 != 0)
	{
		c_index = memory_address % 16;
		str[counter2] = hexadecimal_list[c_index];
		memory_address /= 16;
		*counter += 1;
		counter2++;
	}
	c_index = memory_address % 16;
	str[counter2] = hexadecimal_list[c_index];
	str[counter2 + 1] = '\0';
	counter2 = ft_strlen(str);
	while(counter2 > 0)
	{
		ft_putchar_fd(str[counter2],1);
		counter2--;
	}
	ft_putchar_fd(str[0],1);
	free(str);
	*counter += 1;
}

void hexadecimal_mode(unsigned int integer, int *counter
,int *counter3, int *counter4)
{
	char *hexadecimal_list;
	int c_index;
	size_t counter2;
	char *str;

	str = (char *)malloc(11*sizeof(char));
	hexadecimal_list = "0123456789abcdef";
	counter2 = 0;
	while(integer / 16 != 0)
	{
		c_index = integer % 16;
		str[counter2] = hexadecimal_list[c_index];
		integer /= 16;
		*counter += 1;
		counter2++;
	}
	c_index = integer % 16;
	str[counter2] = hexadecimal_list[c_index];
	str[counter2 + 1] = '\0';
	counter2 = ft_strlen(str);
	while(counter2 > 0)
	{
		ft_putchar_fd(str[counter2],1);
		counter2--;
	}
	ft_putchar_fd(str[0],1);
	free(str);
	*counter += 1;
	*counter3 += 1;
	*counter4 += 1;
}

void	pointer_mode(void *pointer, int *counter,
int *counter3, int *counter4)
{
	int counter2;
	char *str;

	counter2 = 0;
	uintptr_t memory_int = (uintptr_t)pointer;
	str = "0x";
	ft_putstr_fd(str, 1);
	decimal_to_hex(memory_int,counter);
	*counter += counter2 + 2;
	*counter3 += 1;
	*counter4 += 1;
}