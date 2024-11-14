/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:30:06 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/14 19:30:20 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handel_specifier(char speci, va_list args ,int *count)
{
	if (speci == 'c')
		ft_printf_c((char)va_arg(args, int), count);
	else if (speci == 's')
		ft_printf_s(va_arg(args, char*), count);
	else if (speci == 'p')
		ft_printf_p(va_arg(args, void*), count);
	else if (speci == 'd' || speci == 'i')
		ft_printf_d(va_arg(args, int), count);
	else if (speci == '%')
		ft_printf_per(count);
	else if (speci == 'u')
		ft_printf_u(va_arg(args, unsigned int), count);
	else if (speci == 'x')
		ft_printf_hexlower(va_arg(args, unsigned int), count);
	else if (speci == 'X')
		ft_printf_hexupper(va_arg(args, unsigned int), count);
	return(*count);
}

int	ft_printf(const char *a, ...)
{
	va_list	args;
	int count;

	count = 0;
	va_start(args, a);
	while (*a && count != -1)
	{
		if (*a == '%')
		{
			a++;
			// count = count + 1;
			if(*a != 'c' && *a != 's' && *a != 'p' && *a != 'd' && *a != 'i' && *a != '%' && *a != 'u' && *a != 'x' && *a != 'X')
				return(-1);
			// 	count = count + 1;
			handel_specifier(*a, args, &count);
		}
		else 
			ft_printf_c(*a, &count);
		a++;
	}
	va_end(args);
	return (count);
}
