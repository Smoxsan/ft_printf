/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexlower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:29:39 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/15 10:12:11 by fkonig           ###   ########.fr       */
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

int	ft_printf_hexlower(unsigned long c, int *count)
{
	char	*hex_digits;
	int		hex_length;
	char	*hex_return;

	hex_length = hexlen(c);
	hex_return = ft_calloc(hex_length + 1, sizeof(char));
	hex_digits = "0123456789abcdef";
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
// void run_test(unsigned long num) {
//     int count_ft = 0;
//     int count_std = 0;

//     // Using your custom ft_printf_hexlower
//     printf("Testing number: %lu\n", num);
//     printf("ft_printf_hexlower: ");
//     ft_printf_hexlower(num, &count_ft);
//     printf(" | Characters printed by ft_printf_hexlower: %d\n", count_ft);

//     // Using the standard printf for comparison
//     printf("Standard printf (lowercase): ");
//     count_std = printf("0x%lx", num);
//     printf(" | Characters printed by printf: %d\n", count_std);

//     // Uppercase comparison for completeness
//     printf("ft_printf_hexupper: ");
//     count_ft = 0;
//     ft_printf_hexupper(num, &count_ft);
//     printf(" | Characters printed by ft_printf_hexupper: %d\n", count_ft);

//     printf("Standard printf (uppercase): ");
//     count_std = printf("0x%lX", num);
//     printf(" | Characters printed by printf: %d\n", count_std);

//     printf("\n------------------------------\n");
// }

// int main() {
//     // Test cases
//     unsigned long test_cases[] = {
//         0,                  // Zero case
//         1,                  // Small number
//         15,                 // Edge of a single hex digit
//         16,                 // Start of double hex digit
//         255,                // Maximum single-byte value
//         4095,               // End of three hex digits
//         65535,              // Maximum two-byte value
//         1048576,            // Large number in hex
//         0xFFFFFFFF,         // Maximum unsigned int (32-bit)
//         0xFFFFFFFFFFFFFFFF, // Maximum unsigned long (64-bit)
//         0x123456789ABCDEF,  // All digits used
//     };

//     int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

//     // Loop through test cases
//     for (int i = 0; i < num_tests; i++) {
//         run_test(test_cases[i]);
//     }

//     return 0;
// }
