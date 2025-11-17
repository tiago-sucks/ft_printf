/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimao-g <tsimao-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 18:57:13 by tiago             #+#    #+#             */
/*   Updated: 2025/11/17 19:21:13 by tsimao-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//static int ft_conversion(const char type, va_list vargs);


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

#include <limits.h> //library para limites de casts

int main(void)
{
    char			c = 'A';
    char			*s = "Hello World";
    char			*null_s = NULL;
    void			*p = (void *)198723;
    void			*null_p = NULL;
    int				d = -42;
    int				i = 123;
    unsigned int	u = 4294967295;
    unsigned int	x = 255;
    unsigned int	X = 255;
    int				zero = 0;
    int				negative = -1;
    unsigned int	large_hex = 0xDEADBEEF;

    printf("=== Testing printf format specifiers ===\n\n");

    printf("%%c (character):\n");
    printf("  Standard: %c\n", c);
    printf("  NULL char (empty output): %c\n", '\0');
    printf("  Control char (tab): %c|\n", '\t');
    printf("  Digit char: %c\n\n", '5');

    printf("%%s (string):\n");
    printf("  Standard: %s\n", s);
    printf("  NULL string: %s\n", null_s);
    printf("  Empty string: '%s'\n", "");
    printf("  String with spaces: '%s'\n\n", "Hello World Test");

    printf("%%p (pointer):\n");
    printf("  Standard: %p\n", p);
    printf("  NULL pointer: %p\n", null_p);
    printf("  High address: %p\n\n", (void *)0xFFFFFFFF);

    printf("%%d (signed integer):\n");
    printf("  Positive: %d\n", 42);
    printf("  Negative: %d\n", d);
    printf("  Zero: %d\n", zero);
    printf("  INT_MIN: %d\n", INT_MIN);
    printf("  INT_MAX: %d\n\n", INT_MAX);

    printf("%%i (signed integer):\n");
    printf("  Positive: %i\n", i);
    printf("  Negative: %i\n", negative);
    printf("  Zero: %i\n", zero);
    printf("  INT_MIN: %i\n", INT_MIN);
    printf("  INT_MAX: %i\n\n", INT_MAX);
	printf("  INT_MAX: %i\n\n", INT_MAX);

    printf("%%u (unsigned integer):\n");
    printf("  Small value: %u\n", 42);
    printf("  Zero: %u\n", zero);
    printf("  UINT_MAX: %u\n\n",UINT_MAX);

    printf("%%x (hex lowercase):\n");
    printf("  Zero: %x\n", 0);
    printf("  Small (15): %x\n", 15);
    printf("  Standard (255): %x\n", 255);
    printf("  Large (4095): %x\n", 4095);
    printf("  0xDEADBEEF: %x\n\n", large_hex);

    printf("%%X (hex uppercase):\n");
    printf("  Zero: %X\n", 0);
    printf("  Small (15): %X\n", 15);
    printf("  Standard (255): %X\n", 255);
    printf("  Large (4095): %X\n", 4095);
    printf("  0xDEADBEEF: %X\n\n", large_hex);

    printf("%%%% (percent sign):\n");
    printf("  Single: %%\n");
    printf("  Double: %%%%\n");
    printf("  Triple: %%%%%%\n\n");

    printf("=== Complex Mixed Cases ===\n");
    printf("All together: %c %s %p %d %u %x %X %%\n", c, s, p, d, u, x, X);
    printf("Negatives: %d %u %x\n", -1, (unsigned int)(-1), (unsigned int)(-1));
    printf("Edge values: %d %u\n", INT_MIN,UINT_MAX);

    return (0);
}