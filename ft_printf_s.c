/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:57 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/15 09:46:15 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *s, int *count)
{
	int		rar;
	char	*nah;

	nah = "(null)";
	rar = 0;
	if (s == NULL)
	{
		while (nah[rar])
		{
			ft_printf_c(nah[rar], count);
			rar++;
		}
		return (0);
	}
	while (s[rar])
	{
		ft_printf_c(s[rar], count);
		rar++;
	}
	return (*count);
}
