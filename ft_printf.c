/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smox <smox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:30:06 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/04 11:04:50 by smox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(const char *a, ...)
{
	va_list args;
	va_start(args, a);
	while (a++)
	{
		if (*a == '%')
		{
			a++;
			if (*a == 'c'){
				char c = (char)va_arg(args, int);
				ft_printf_c(c);	}
			else if (*a == 's'){
				char *s = va_arg(args, char*);
				ft_printf_s(s);}
			else if (*a == 'p'){
				void *p = va_arg(args, void*);
				ft_printf_p(p);}
			else if (*a == 'd' ||*a == 'i'){
				int d = va_arg(args, int);
				ft_printf_d(d);}
			else if (*a == '%')
				ft_printf_per(a);
			else if (*a == 'u'){
				unsigned int u = va_arg(args, unsigned int);
				ft_printf_u(u);}
			else if (*a == 'x'){
				unsigned int x = va_arg(args, unsigned int);
				ft_printf_hexlower(x);}
			else if (*a == 'X'){
				unsigned int X = va_arg(args, unsigned int);
				ft_printf_hexupper(X);}
		}
	}
	va_end(args);
}
