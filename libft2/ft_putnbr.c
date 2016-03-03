/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:11:49 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/30 14:11:56 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putnbr(int n)
{
	char	c;

	if (n / 10)
		ft_putnbr(n / 10);
	if (n < 0 && n > -10)
		write(1, "-", 1);
	n %= 10;
	if (n < 0)
		n *= -1;
	c = n + '0';
	write(1, &c, 1);
}