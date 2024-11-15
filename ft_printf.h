/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:30:14 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/15 09:56:06 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# define FT_PRINTF_H

int	ft_printf_c(char c, int *count);
int	ft_printf_s(char *s, int *count);
int	ft_printf_p(void *c, int *count);
int	ft_printf_per(int *count);
int	ft_printf_d(int n, int *count);
int	ft_printf_hexlower(unsigned long c, int *count);
int	ft_printf_hexupper(unsigned long c, int *count);
int	ft_printf_i(int n, int *count);
int	ft_printf(const char *a, ...);
int	ft_printf_u(unsigned int n, int *count);
#endif