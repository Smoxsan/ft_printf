/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smox <smox@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:30:14 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/05 14:41:29 by smox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
#include <stdarg.h>
# define FT_PRINTF_H

void	ft_printf_c(char c);
char	*ft_printf_s(char *s);
void	*ft_printf_p(void *c);
void	ft_printf_per(void);
void	ft_printf_d(int n);
void	ft_printf_hexlower(unsigned long c);
void	ft_printf_hexupper(unsigned long c);
void	ft_printf_i(int n);
int	ft_printf(const char *a, ...);
int	ft_printf_u(unsigned int n);
#endif