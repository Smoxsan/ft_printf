/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smox <smox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:51 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/01 12:44:25 by smox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_p(void *c)
{
	ft_printf_hexlower((unsigned long)c);
	write(1, "\n", 1);
}