/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:31 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/14 18:00:23 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(char c, int *count)
{
	if (*count == -1)
		return(-1);
	*count += write(1, &c, 1);
	return(*count);
}

//int main()
//{
//	ft_printf_c(8);
//}