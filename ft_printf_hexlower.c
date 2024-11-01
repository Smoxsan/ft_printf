/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexlower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smox <smox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:39 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/01 12:44:09 by smox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hexlower(unsigned long c)
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
	while (i >= 0)
		hex[i--] = '0';
	write(1, hex, 16);
	write(1, "\n", 1);
}
