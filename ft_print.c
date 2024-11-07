/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkonig <fkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:30:06 by fkonig            #+#    #+#             */
/*   Updated: 2024/11/07 13:48:32 by fkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handel_specifier(char speci, va_list args)
{
	char			c;
	char			*s;
	void			*p;
	int				d;
	unsigned int	u;
	unsigned int 	x;
	unsigned int 	X;

	if (speci == 'c')
	{
		c = (char)va_arg(args, int);
		ft_printf_c(c);
	}
	else if (speci == 's')
	{
		s = va_arg(args, char*);
		ft_printf_s(s);
	}
	else if (speci == 'p')
	{
		p = va_arg(args, void*);
		ft_printf_p(p);
	}
	else if (speci == 'd' || speci == 'i')
	{
		d = va_arg(args, int);
		ft_printf_d(d);
	}
	else if (speci == '%')
		ft_printf_per();
	else if (speci == 'u')
	{
		u = va_arg(args, unsigned int);
		ft_printf_u(u);
	}
	else if (speci == 'x')
	{
		x = va_arg(args, unsigned int);
		ft_printf_hexlower(x);
	}
	else if (speci == 'X')
	{
		X = va_arg(args, unsigned int);
		ft_printf_hexupper(X);
	}
}

int	ft_printf(const char *a, ...)
{
	va_list	args;

	va_start(args, a);
	while (*a)
	{
		if (*a == '%')
		{
			a++;
			while(*a != 'c' && *a != 's' && *a != 'p' && *a != 'd' && *a != 'i' && *a != '%' && *a != 'u' && *a != 'x' && *a != 'X')
				a++;
			handel_specifier(*a, args);
		}
		else 
			write(1, a, 1);
		a++;
	}
	va_end(args);
	return (0);
}

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
    // Test character
    ft_printf("Character: %c\n", 'A');          // Standard character test
    ft_printf("Character: %c\n", '\0');         // Null character

    // Test string
    ft_printf("String: %s\n", "Hello, world!"); // Normal string
    ft_printf("String: %s\n", "");              // Empty string
    ft_printf("String: %s\n", NULL);            // NULL string (may cause crash if not handled)

    // Test pointer (address)
    int *ptr = NULL;
    ft_printf("Pointer: %p\n", ptr);            // NULL pointer
    int num = 42;
    ptr = &num;
    ft_printf("Pointer: %p\n", ptr);            // Non-NULL pointer
    
    // Test integer
    ft_printf("Integer: %d\n", -123);           // Negative integer
    ft_printf("Integer: %d\n", 0);              // Zero
    ft_printf("Integer: %d\n", 123);            // Positive integer
    ft_printf("Integer: %d\n", INT_MAX);        // Edge case (max int value)
    ft_printf("Integer: %d\n", INT_MIN);        // Edge case (min int value)

    // Test unsigned integer
    ft_printf("Unsigned integer: %u\n", 12345); // Standard unsigned integer
    ft_printf("Unsigned integer: %u\n", 0);     // Zero
    ft_printf("Unsigned integer: %u\n", UINT_MAX); // Edge case (max unsigned int)

    // Test hexadecimal (lowercase)
    ft_printf("Hexadecimal (lower): %x\n", 255); // Standard hex
    ft_printf("Hexadecimal (lower): %x\n", 0);   // Zero
    ft_printf("Hexadecimal (lower): %x\n", UINT_MAX); // Edge case (max unsigned int)

    // Test hexadecimal (uppercase)
    ft_printf("Hexadecimal (upper): %X\n", 255); // Standard hex (uppercase)
    ft_printf("Hexadecimal (upper): %X\n", 0);   // Zero
    ft_printf("Hexadecimal (upper): %X\n", UINT_MAX); // Edge case (max unsigned int)

    // Test percentage sign
    ft_printf("Percentage: %%\n");              // Printing just the '%' character
    
    // Test with mixed format specifiers
    ft_printf("Mixed format: %d, %s, %x, %u\n", -123, "Hello", 255, 12345);
    
    // Test edge case with very large numbers
    ft_printf("Large unsigned number: %u\n", 4294967295); // Max unsigned 32-bit number
    ft_printf("Large hexadecimal (lower): %x\n", 4294967295); // Max unsigned 32-bit number in hex (lowercase)
    ft_printf("Large hexadecimal (upper): %X\n", 4294967295); // Max unsigned 32-bit number in hex (uppercase)

    // Test invalid format specifier
    ft_printf("Invalid specifier: %z\n");        // Invalid format specifier (e.g. '%z')

    // Test edge cases with width and precision
    ft_printf("Width & Precision - Integer: %10d\n", 42);          // Integer with width
    ft_printf("Width & Precision - Integer: %.5d\n", 42);          // Integer with precision
    ft_printf("Width & Precision - String: %10s\n", "Hello");      // String with width
    ft_printf("Width & Precision - String: %.3s\n", "Hello");      // String with precision
    ft_printf("Width & Precision - Hexadecimal: %10x\n", 255);     // Hexadecimal with width
    ft_printf("Width & Precision - Hexadecimal: %.5x\n", 255);     // Hexadecimal with precision
    
    return 0;
}

