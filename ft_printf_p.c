/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:51 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/15 13:39:28 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(void *c, int *count)
{
	*count += write(1, "0x", 2);
	if (*count == -1)
		return (*count);
	ft_printf_hexlower((unsigned long)c, count);
	return (*count);
}
