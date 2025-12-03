/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:05:42 by tiago             #+#    #+#             */
/*   Updated: 2025/11/30 20:06:04 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}


int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		return (write (1, "(null)", 6) == -1);
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
	long		sum;
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
	sum = nb % 10 + '0';
	if (nb > 9)
	{
		temp = ft_putnbr(nb / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &sum, 1) == -1) //ele printa sempre o número, mas verifica se a sum for -1, retorna -1
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
	if (nbr > 15)
	{
		temp = ft_puthex((nbr / 16), up);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	mod = nbr % 16;
	if (write(1, &base[mod], 1) == -1) //putnbr mas converte o numero para a base de hexadecimal usando a devida posição do pointer base
		return (-1);
	len += 1;
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	temp;

	len = 0;
	temp = 0;
	if (ft_putstr("0x") == -1)
		return (0);
	len += 2;
	temp = ft_putnbr_hexa((unsigned long)ptr, 'x');
	if (temp == -1)
		return (len);
	len += temp;
	return (len);
}

int main()
{
	char *dor = NULL;
	int nomerus = 1235;
	char up = 'x';

	printf("\n%d\n", ft_puthex(nomerus, up));
	printf("\n%d\n", ft_putstr(dor));
}

//$? retorna sempre o ultimo return da main