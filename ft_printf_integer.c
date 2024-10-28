#include "ft_printf.h"
void	ft_printf_integer(int n)
{
	if (n == -2147483648)
	{
		ft_printf_char('-');
		ft_printf_char('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_printf_char('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_printf_char(n / 10);
	}
	ft_printf_char((n % 10) + '0');
}