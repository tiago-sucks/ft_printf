/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimao-g <tsimao-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:05:42 by tiago             #+#    #+#             */
/*   Updated: 2026/01/07 15:56:38 by tsimao-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*s != '\0')
	{
		if (write(1, s, 1) == -1)
			return (-1);
		len++;
		s++;
	}
	return (len);
}

int	ft_putnbr(long nb)
{
	char		sum;
	int			len;
	int			temp;

	len = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		nb *= -1;
	}
	if (nb > 9)
	{
		temp = ft_putnbr(nb / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	sum = (nb % 10) + '0';
	if (write(1, &sum, 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_puthex(unsigned long nbr, char up)
{
	int		len;
	int		mod;
	char	*base;
	int		temp;

	mod = 0;
	len = 0;
	if (up == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr >= 16)
	{
		temp = ft_puthex((nbr / 16), up);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	mod = nbr % 16;
	if (write(1, &base[mod], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	temp;

	if (!ptr)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	len = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += 2;
	temp = ft_puthex((unsigned long)ptr, 'x');
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}
