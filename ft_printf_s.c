/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:57 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/11 17:17:38 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_printf_s(char *s, int *count)
{
	int rar;
	
	rar = 0;
	if(s == NULL)
	{
		ft_printf_s("(NULL)", count);
		return(0);
	}
	while (s[rar])
	{
		
		ft_printf_c(s[rar], count);
		rar++;
	}
	return(0);
}