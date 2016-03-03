/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_putnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 15:55:34 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:09:39 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			ft_char_spe(int c)
{
	char	*ignor;
	int		i;

	ignor = "\n\v\t\r\f ";
	i = 0;
	while (i < 6)
	{
		if (ignor[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int			ft_atoi(char *str)
{
	int		r;
	int		neg;

	r = 0;
	neg = 1;
	while (ft_char_spe(*str))
	{
		str++;
	}
	while ((*str == '+' || *str == '-') && neg == 1)
	{
		if (*str == '-' || *(str + 1) == '+')
		{
			neg = -1;
			if (*(str - 1) == '+')
				str--;
		}
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str) - '0';
		str++;
	}
	return (r * neg);
}

void		ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n = -147483648;
		}
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(48 + n);
}
