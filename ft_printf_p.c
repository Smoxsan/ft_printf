/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:51 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/15 09:52:18 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(void *c, int *count)
{
	int		rar;
	char	*nah;

	rar = 0;
	nah = "(nil)";
	if (c == NULL)
	{
		while (nah[rar])
		{
			ft_printf_c(nah[rar], count);
			rar++;
		}
	}
	else
	{
		write(1, "0x", 2);
		*count += 2;
		ft_printf_hexlower((unsigned long)c, count);
	}
	return (*count);
}
