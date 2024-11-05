/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smox <smox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:30:06 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/05 15:19:05 by smox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

satic void	handel_specifier(char speci, va_list args)
{
	char			c;
	char			*s;
	void			*p;
	int				d;
	unsigned int	u;
	unsigned int 	x:
	unsigned int 	X;

	if (*a == 'c')
	{
		c = (char)va_arg(args, int);
		ft_printf_c(c);
	}
	else if (*a == 's')
	{
		*s = va_arg(args, char*);
		ft_printf_s(s);
	}
	else if (*a == 'p')
	{
		*p = va_arg(args, void*);
		ft_printf_p(p);
	}
	else if (*a == 'd' || *a == 'i')
	{
		d = va_arg(args, int);
		ft_printf_d(d);
	}
	else if (*a == '%')
		ft_printf_per();
	else if (*a == 'u')
	{
		u = va_arg(args, unsigned int);
		ft_printf_u(u);
	}
	else if (*a == 'x')
	{
		x = va_arg(args, unsigned int);
		ft_printf_hexlower(x);
	}
	else if (*a == 'X')
	{
		X = va_arg(args, unsigned int);
		ft_printf_hexupper(X);
	}
}

int	ft_printf(const char *a, ...)
{
	va_list	args;

	va_start(args, a);
	while (a++)
	{
		if (*a == '%')
		{
			a++;
			handel_specifier(*a, args);
		}
	}
	va_end(args);
	return (0);
}
