/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:30:06 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/12 12:00:47 by fkonig           ###   ########.fr       */
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
			// count = count + 1;
			if(*a != 'c' && *a != 's' && *a != 'p' && *a != 'd' && *a != 'i' && *a != '%' && *a != 'u' && *a != 'x' && *a != 'X')
				return(-1);
			// 	count = count + 1;
			handel_specifier(*a, args, &count);
		}
		else 
			ft_printf_c(*a, &count);
		a++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int printed_chars = 0;
    
	printed_chars = ft_printf("Character: %c\n", 'A');          // Standard character test
	printf("ft_printf printed %d characters.\n", printed_chars);
    printed_chars = ft_printf("Character: %c\n", '\0');         // Null character
	printf("ft_printf printed %d characters.\n", printed_chars);

    // Test string
    printed_chars = ft_printf("String: %s\n", "Hello, world!");
	printf("ft_printf printed %d characters.\n", printed_chars); // Normal string
    printed_chars = ft_printf("String: %s\n", "");              
	printf("ft_printf printed %d characters.\n", printed_chars);// Empty string
    printed_chars = ft_printf("String: %s\n", NULL);            
	printf("ft_printf printed %d characters.\n", printed_chars);// NULL string (may cause crash if not handled)

    // Test pointer (address)
    int *ptr = NULL;
    printed_chars = ft_printf("Pointer: %p\n", ptr);            
	printf("ft_printf printed %d characters.\n", printed_chars);// NULL pointer
    int num = 42;
    ptr = &num;
    printed_chars = ft_printf("Pointer: %p\n", ptr);            
	printf("ft_printf printed %d characters.\n", printed_chars);// Non-NULL pointer
    
    // Test integer
    printed_chars = ft_printf("Integer: %d\n", -123);        
	printf("ft_printf printed %d characters.\n", printed_chars);   // Negative integer
    printed_chars = ft_printf("Integer: %d\n", 0);              
	printf("ft_printf printed %d characters.\n", printed_chars);// Zero
    printed_chars = ft_printf("Integer: %d\n", 123);            
	printf("ft_printf printed %d characters.\n", printed_chars);// Positive integer
    printed_chars = ft_printf("Integer: %d\n", INT_MAX);        
	printf("ft_printf printed %d characters.\n", printed_chars);// Edge case (max int value)
    printed_chars = ft_printf("Integer: %d\n", INT_MIN);        
	printf("ft_printf printed %d characters.\n", printed_chars);// Edge case (min int value)

    // Test unsigned integer
    printed_chars = ft_printf("Unsigned integer: %u\n", 12345); 
	printf("ft_printf printed %d characters.\n", printed_chars);// Standard unsigned integer
    printed_chars = ft_printf("Unsigned integer: %u\n", 0);     
	printf("ft_printf printed %d characters.\n", printed_chars);// Zero
    printed_chars = ft_printf("Unsigned integer: %u\n", UINT_MAX);
	printf("ft_printf printed %d characters.\n", printed_chars); // Edge case (max unsigned int)

    // Test hexadecimal (lowercase)
    printed_chars = ft_printf("Hexadecimal (lower): %x\n", 255);
	printf("ft_printf printed %d characters.\n", printed_chars); // Standard hex
    printed_chars = ft_printf("Hexadecimal (lower): %x\n", 0);  
	printf("ft_printf printed %d characters.\n", printed_chars); // Zero
    printed_chars = ft_printf("Hexadecimal (lower): %x\n", UINT_MAX);
	printf("ft_printf printed %d characters.\n", printed_chars); // Edge case (max unsigned int)

    // Test hexadecimal (uppercase)
    ft_printf("Hexadecimal (upper): %X\n", 255);
	printf("ft_printf printed %d characters.\n", printed_chars); // Standard hex (uppercase)
    ft_printf("Hexadecimal (upper): %X\n", 0); 
	printf("ft_printf printed %d characters.\n", printed_chars);  // Zero
    ft_printf("Hexadecimal (upper): %X\n", UINT_MAX);
	printf("ft_printf printed %d characters.\n", printed_chars); // Edge case (max unsigned int)

    // Test percentage sign
    printed_chars = ft_printf("Percentage: %%\n");              
	printf("ft_printf printed %d characters.\n", printed_chars);// Printing just the '%' character
    
    // Test with mixed format specifiers
    printed_chars = ft_printf("Mixed format: %d, %s, %x, %u\n", -123, "Hello", 255, 12345);
	printf("ft_printf printed %d characters.\n", printed_chars);
    
    // Test edge case with very large numbers
    printed_chars = ft_printf("Large unsigned number: %u\n", 4294967295); // Max unsigned 32-bit number
	printf("ft_printf printed %d characters.\n", printed_chars);
    printed_chars = ft_printf("Large hexadecimal (lower): %x\n", 4294967295); // Max unsigned 32-bit number in hex (lowercase)
	printf("ft_printf printed %d characters.\n", printed_chars);
    printed_chars = ft_printf("Large hexadecimal (upper): %X\n", 4294967295); 
	printf("ft_printf printed %d characters.\n", printed_chars);// Max unsigned 32-bit number in hex (uppercase)

    // Test invalid format specifier
    ft_printf("Invalid specifier: %z\n");        // Invalid format specifier (e.g. '%z')

    return (0);
}
