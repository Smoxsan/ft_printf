/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:30:14 by fkonig            #+#    #+#             */
/*   Updated: 2024/10/31 17:09:29 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# define FT_PRINTF_H
char	ft_printf_c(char c);
char	*ft_printf_s(char *s);
int	ft_printf_d(int n);
int	ft_printf_i(int n);
char	*ft_printf_p(void *c);
char	ft_printf_per(char i);
unsigned int	ft_printf_u(unsigned int n);
#endif