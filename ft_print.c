/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:30:06 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/11 16:52:36 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handel_specifier(char speci, va_list args ,int *count)
{
	if (speci == 'c')
		ft_printf_c((char)va_arg(args, int), count);
	else if (speci == 's')
		ft_printf_s(va_arg(args, char*), count);
	else if (speci == 'p')
		ft_printf_p(va_arg(args, void*), count);
	else if (speci == 'd' || speci == 'i')
		ft_printf_d(va_arg(args, int), count);
	else if (speci == '%')
		ft_printf_per(count);
	else if (speci == 'u')
		ft_printf_u(va_arg(args, unsigned int), count);
	else if (speci == 'x')
		ft_printf_hexlower(va_arg(args, unsigned int), count);
	else if (speci == 'X')
		ft_printf_hexupper(va_arg(args, unsigned int), count);
	return(0);
}

int	ft_printf(const char *a, ...)
{
	va_list	args;
	int count;

	count = 0;
	va_start(args, a);
	while (*a && count != -1)
	{
		if (*a == '%')
		{
			a++;
			count = count + 1;
			if(*a != 'c' && *a != 's' && *a != 'p' && *a != 'd' && *a != 'i' && *a != '%' && *a != 'u' && *a != 'x' && *a != 'X')
				return(-1);
			// 	count = count + 1;
			count += handel_specifier(*a, args, &count);
		}
		else 
			ft_printf_c(*a, &count);
		a++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>
// #include <limits.h>
// #include "ft_printf.h"

// int main()
// {
//     // Test character
//     printf("Character: %c\n", 'A');          // Standard character test
//     ft_printf("Character: %c\n", 'A');          // Standard character test
//     ft_printf("Character: %c\n", '\0');         // Null character

//     // Test string
//     ft_printf("String: %s\n", "Hello, world!"); // Normal string
//     ft_printf("String: %s\n", "");              // Empty string
//     ft_printf("String: %s\n", NULL);            // NULL string (may cause crash if not handled)

//     // Test pointer (address)
//     int *ptr = NULL;
//     ft_printf("Pointer: %p\n", ptr);            // NULL pointer
//     int num = 42;
//     ptr = &num;
//     ft_printf("Pointer: %p\n", ptr);            // Non-NULL pointer
    
//     // Test integer
//     ft_printf("Integer: %d\n", -123);           // Negative integer
//     ft_printf("Integer: %d\n", 0);              // Zero
//     ft_printf("Integer: %d\n", 123);            // Positive integer
//     ft_printf("Integer: %d\n", INT_MAX);        // Edge case (max int value)
//     ft_printf("Integer: %d\n", INT_MIN);        // Edge case (min int value)

//     // Test unsigned integer
//     ft_printf("Unsigned integer: %u\n", 12345); // Standard unsigned integer
//     ft_printf("Unsigned integer: %u\n", 0);     // Zero
//     ft_printf("Unsigned integer: %u\n", UINT_MAX); // Edge case (max unsigned int)

//     // Test hexadecimal (lowercase)
//     ft_printf("Hexadecimal (lower): %x\n", 255); // Standard hex
//     ft_printf("Hexadecimal (lower): %x\n", 0);   // Zero
//     ft_printf("Hexadecimal (lower): %x\n", UINT_MAX); // Edge case (max unsigned int)

//     // Test hexadecimal (uppercase)
//     ft_printf("Hexadecimal (upper): %X\n", 255); // Standard hex (uppercase)
//     ft_printf("Hexadecimal (upper): %X\n", 0);   // Zero
//     ft_printf("Hexadecimal (upper): %X\n", UINT_MAX); // Edge case (max unsigned int)

//     // Test percentage sign
//     ft_printf("Percentage: %%\n");              // Printing just the '%' character
    
//     // Test with mixed format specifiers
//     ft_printf("Mixed format: %d, %s, %x, %u\n", -123, "Hello", 255, 12345);
    
//     // Test edge case with very large numbers
//     ft_printf("Large unsigned number: %u\n", 4294967295); // Max unsigned 32-bit number
//     ft_printf("Large hexadecimal (lower): %x\n", 4294967295); // Max unsigned 32-bit number in hex (lowercase)
//     ft_printf("Large hexadecimal (upper): %X\n", 4294967295); // Max unsigned 32-bit number in hex (uppercase)

//     // Test invalid format specifier
//     ft_printf("Invalid specifier: %z\n");        // Invalid format specifier (e.g. '%z')

//     // Test edge cases with width and precision
//     ft_printf("Width & Precision - Integer: %10d\n", 42);          // Integer with width
//     ft_printf("Width & Precision - Integer: %.5d\n", 42);          // Integer with precision
//     ft_printf("Width & Precision - String: %10s\n", "Hello");      // String with width
//     ft_printf("Width & Precision - String: %.3s\n", "Hello");      // String with precision
//     ft_printf("Width & Precision - Hexadecimal: %10x\n", 255);     // Hexadecimal with width
//     ft_printf("Width & Precision - Hexadecimal: %.5x\n", 255);     // Hexadecimal with precision
    
//     return 0;
// }
