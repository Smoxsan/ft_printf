/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smox <smox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:31 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/01 12:44:21 by smox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_printf_c(char c)
{
	write(1, &c, 1);
	write(1, "\n", 1);
}

//int main()
//{
//	ft_printf_char(8);
//}