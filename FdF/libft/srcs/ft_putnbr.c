/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:25:59 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:26:00 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n));
	else if (n > 9)
		return (ft_putnbr(n / 10) + ft_putchar(n % 10 + '0'));
	else
		return (ft_putchar(n + '0'));
}
