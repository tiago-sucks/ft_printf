/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiago <tiago@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:05:42 by tiago             #+#    #+#             */
/*   Updated: 2025/11/25 20:31:32 by tiago            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_strlen(char *s)
{
	int i;
	
	i = 0;
	while(s[i])
	{
		i++;
	}
	return (i);
}




int	ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int len;
	
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = (int)ft_strlen(s);
	if (write(1, s, len) == -1)
		return (-1);
	return (len);
}

int	ft_putnbr(long nb)
{
	long		sum;
	int			len;
	int			aux;

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
		aux = ft_putnbr(nb / 10);
		if (aux == -1)
			return (-1);
		len += aux;
	}
	if (write(1, &sum, 1) == -1)
		return (-1);
	len++;
	return (len);
}

int main()
{
	char dor[] = "teste";
	printf("\n%d", ft_putstr(dor));
}