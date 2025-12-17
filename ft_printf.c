/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:57:13 by tiago             #+#    #+#             */
/*   Updated: 2025/12/17 21:12:55 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(const char type, va_list vargs)
{
	if (type == 'c')
		return (ft_putchar(va_arg(vargs, int)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(vargs, unsigned int)));
	else if ((type == 'i') || (type == 'd'))
		return (ft_putnbr(va_arg(vargs, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	else if (type == 'x' || type == 'X')
		return (ft_puthex(va_arg(vargs, unsigned int), type));
	else if (type == 'p')
		return (ft_putptr(va_arg(vargs, void *)));
	else if (type == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(char const *str, ...)
{
	va_list	vargs;
	int		len;
	int		check;

	va_start(vargs, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			check = ft_conversion(*(++str), vargs);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			if (write(1, str, 1) == -1)
				return (-1);
			len++;
		}
		str++;
	}
	va_end(vargs);
	return (len);
}

// %c - character
// NULL char: retorna nada

// %s - string
// NULL: retorna "(null)"

// %p - point address
// NULL: "(nil)"

// %d and %i - signed int
// %u - unsigned int
// %x - hexadecimal lowercase
// %X - hexadecimal uppercase
// %% - followed by another % character will write a single % to the stream

// #include <limits.h> //library para limites de casts

// int main(void)
// {
// 	int x = 42;

// 	//%c tests
// 	ft_printf("--- %%c tests ---\n");
// 	ft_printf("%c\n", 'a');
// 	ft_printf("%c%c%c\n", 'A', 'B', 'C');
// 	ft_printf("%c\n", 0);

// 	//%s tests
// 	ft_printf("\n--- %%s tests ---\n");
// 	ft_printf("%s\n", "Hello");
// 	ft_printf("%s\n", "");
// 	ft_printf("%s\n", (char *)NULL);

// 	//%p tests
// 	ft_printf("\n--- %%p tests ---\n");
// 	ft_printf("%p\n", &x);
// 	ft_printf("%p\n", NULL);
// 	ft_printf("%p\n", (void *)0xFFFFFFFF);

// 	//%d tests
// 	ft_printf("\n--- %%d tests ---\n");
// 	ft_printf("%d\n", 0);
// 	ft_printf("%d\n", 42);
// 	ft_printf("%d\n", -42);
// 	ft_printf("%d\n", INT_MAX);
// 	ft_printf("%d\n", INT_MIN);

// 	//%i tests
// 	ft_printf("\n--- %%i tests ---\n");
// 	ft_printf("%i\n", 0);
// 	ft_printf("%i\n", 123);
// 	ft_printf("%i\n", -123);
// 	ft_printf("%i\n", INT_MAX);
// 	ft_printf("%i\n", INT_MIN);

// 	//%u tests
// 	ft_printf("\n--- %%u tests ---\n");
// 	ft_printf("%u\n", 0);
// 	ft_printf("%u\n", 42);
// 	ft_printf("%u\n", UINT_MAX);
// 	ft_printf("%u\n", -1);

// 	//%x tests
// 	ft_printf("\n--- %%x tests ---\n");
// 	ft_printf("%x\n", 0);
// 	ft_printf("%x\n", 42);
// 	ft_printf("%x\n", 255);
// 	ft_printf("%x\n", INT_MAX);
// 	ft_printf("%x\n", UINT_MAX);

// 	//%X tests
// 	ft_printf("\n--- %%X tests ---\n");
// 	ft_printf("%X\n", 0);
// 	ft_printf("%X\n", 42);
// 	ft_printf("%X\n", 255);
// 	ft_printf("%X\n", INT_MAX);
// 	ft_printf("%X\n", UINT_MAX);

// 	//%% tests
// 	ft_printf("\n--- %%%% tests ---\n");
// 	ft_printf("%%\n");
// 	ft_printf("%%%%\n");
// 	ft_printf("100%%\n");

// 	ft_printf("\n--- other tests ---\n");
// 	ft_printf("%c %s %p %d %i %u %x %X %%\n", 'Z', "qw", &x, -1, 2, 42, 42, 42);

// 	return (0);
// }
