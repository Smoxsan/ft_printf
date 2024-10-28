#include "ft_printf.h"
void ft_printf_char(char c)
{
	write(1, &c, 1);
}

//int main()
//{
//	ft_printf_char(8);
//}