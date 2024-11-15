/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexupper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:39 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/15 10:06:03 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*ft_calloc(size_t num_elements, size_t element_size)
{
	char	*ptr;
	size_t	size;
	size_t	i;

	size = num_elements * element_size;
	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

static int	hexlen(unsigned long c)
{
	int	hex_len;

	hex_len = 0;
	if (c == 0)
	{
		hex_len = 1;
	}
	else
	{
		while (c > 0)
		{
			c /= 16;
			hex_len++;
		}
	}
	return (hex_len);
}

int	ft_printf_hexupper(unsigned long c, int *count)
{
	char	*hex_digits;
	int		hex_length;
	char	*hex_return;

	hex_length = hexlen(c);
	hex_return = ft_calloc(hex_length + 1, sizeof(char));
	hex_digits = "0123456789ABCDEF";
	hex_length = hex_length - 1;
	if (hex_return == NULL)
		return (*count);
	if (c == 0)
		hex_return[0] = '0';
	while (c > 0)
	{
		hex_return[hex_length--] = hex_digits[c % 16];
		c /= 16;
	}
	hex_length = 0;
	while (hex_return[hex_length] != '\0')
	{
		ft_printf_c(hex_return[hex_length], count);
		hex_length++;
	}
	free(hex_return);
	return (*count);
}
