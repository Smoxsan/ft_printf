/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexupper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:39 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/07 12:50:43 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hexupper(unsigned long c)
{
	char	*hex_digits;
	char	hex[16];
	int	i;

	i = 15;
	hex_digits = "0123456789ABCDEF";
	while (c > 0)
	{
		hex[i--] = hex_digits[c % 16];
		c /= 16;
	}
	write(1, "0x", 2);
	while (i >= 0)
		hex[i--] = '0';
	write(1, hex, 16);
}
