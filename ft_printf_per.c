/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_per.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smox <smox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:32:16 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/04 10:59:08 by smox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_printf_per(const char *a)
{
	write(1, '%', 1);
	write(1, "\n", 1);
}