/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smox <smox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:30:14 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/01 03:36:33 by smox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# define FT_PRINTF_H

int	ft_printf_d(int n);
int	ft_printf_i(int n);
unsigned int	ft_printf_u(unsigned int n);
char	ft_printf_c(char c);
char	*ft_printf_s(char *s);
void	*ft_printf_p(void *c);
char	ft_printf_per(char i);
#endif