/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 13:58:13 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/30 13:58:15 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_putnbr_in_str(int n, char *str)
{
	if (n / 10)
		ft_putnbr_in_str(n / 10, str - 1);
	n %= 10;
	if (n < 0)
		n *= -1;
	*str = n + '0';
}

char		*ft_itoa(int n)
{
	int		tmp;
	int		len;
	char	*str;

	len = (n <= 0 ? 1 : 0);
	tmp = n;
	while (tmp)
	{
		++len;
		tmp /= 10;
	}
	if ((str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	str[len] = 0;
	if (n < 0)
		str[0] = '-';
	ft_putnbr_in_str(n, str + len - 1);
	return (str);
}
