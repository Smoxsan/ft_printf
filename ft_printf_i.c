/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:46 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/15 09:43:41 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_i(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_printf_c('-', count);
		ft_printf_c('2', count);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_printf_c('-', count);
		n = -n;
	}
	if (n >= 10)
	{
		ft_printf_i(n / 10, count);
	}
	ft_printf_c((n % 10) + '0', count);
	return (0);
}
