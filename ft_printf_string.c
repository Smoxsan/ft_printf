#include "ft_printf.h"
void ft_printf_string(char *s)
{
	while(*s)
	{
		write(1, s, 1);
		s++;
	}
}