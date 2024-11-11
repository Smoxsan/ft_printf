/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexlower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:39 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/11 17:15:31 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexlower(unsigned long c, int *count)
{
	char	*hex_digits;
	char	hex[16];
	int	i;

	i = 15;
	hex_digits = "0123456789abcdef";
	while (c > 0)
	{
		hex[i--] = hex_digits[c % 16];
		c /= 16;
	}
	write(1, "0x", 2);
	*count = 2;
	while (i >= 0)
		hex[i--] = '0';
	*count = *count + 16;
	write(1, hex, 16);
	return(*count);
}
