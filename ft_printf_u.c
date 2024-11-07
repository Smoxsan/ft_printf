/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:30:02 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/07 12:51:26 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(unsigned int n)
{
	if (n >= 10)
	{
		ft_printf_u(n / 10);
	}
	ft_printf_c((n % 10) + '0');
	return (0);
}

// int main(void)
// {
//     // Test cases for ft_printf_u
//     ft_printf_u(0);                       // Expected output: 0
//     ft_printf_c('\n');                    // New line

//     ft_printf_u(42);                      // Expected output: 42
//     ft_printf_c('\n');                    // New line

//     ft_printf_u(2147483647);              // Expected output: 2147483647
//     ft_printf_c('\n');                    // New line

//     ft_printf_u(4294967295);              // Expected output: 4294967295 (max value for unsigned int)
//     ft_printf_c('\n');                    // New line

//     ft_printf_u(123456789);               // Expected output: 123456789
//     ft_printf_c('\n');                    // New line

//     ft_printf_u(987654321);               // Expected output: 987654321
//     ft_printf_c('\n');                    // New line

//     return 0;
// }