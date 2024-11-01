/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smox <smox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:30:06 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/01 18:42:34 by smox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(const char *a, ...)
{
	while (*a)
	{
		if (*a == '%')
		{
			a++;
			if ('c')
				ft_printf_c()	
			else if ('s')
				ft_printf_s
			else if ('p')
				ft_printf_p
			else if ('d')
				ft_printf_d
			else if ("%")
				ft_printf_per
			else if ('i')
				ft_printf_i
			else if ('u')
				ft_printf_u
			else if ('x')
				ft_printf_hexlower
			else if ('X')
				ft_printf_hexupper
		}
	}
}
