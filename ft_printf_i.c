/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:46 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/11 17:16:29 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_i(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_printf_c('-', count);
		ft_printf_c('2', count);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_printf_c('-', count);
		n = -n;
	}
	if (n >= 10)
	{
		ft_printf_i(n / 10, count);
	}
	ft_printf_c((n % 10) + '0', count);
	return(0);
}

//int main(void)
// {
//     // Test cases for ft_printf_d
//     ft_printf_i(0);                       // Expected output: 0
//     ft_printf_c('k');                    // New line

//     ft_printf_i(42);                      // Expected output: 42
//     ft_printf_c('\n');                    // New line

//     ft_printf_i(-42);                     // Expected output: -42
//     ft_printf_c('\n');                    // New line

//     ft_printf_i(2147483647);              // Expected output: 2147483647
//     ft_printf_c('\n');                    // New line

//     ft_printf_i(-2147483648);             // Expected output: -2147483648
//     ft_printf_c('\n');                    // New line

//     ft_printf_i(123456789);               // Expected output: 123456789
//     ft_printf_c('\n');                    // New line

//     ft_printf_i(-123456789);              // Expected output: -123456789
//     ft_printf_c('\n');                    // New line

//     return 0;
// }