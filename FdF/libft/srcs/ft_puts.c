/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:26:23 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:26:24 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_puthexi(int n, int upper)
{
	if (n > -1 && n < 10)
		return (ft_putchar(n + '0'));
	else if (upper)
		return (ft_putchar(n - 10 + 'A'));
	else
		return (ft_putchar(n - 10 + 'a'));
}

int		ft_puthexi_fd(int n, int upper, int fd)
{
	if (n > -1 && n < 10)
		return (ft_putchar_fd(n + '0', fd));
	else if (upper)
		return (ft_putchar_fd(n - 10 + 'A', fd));
	else
		return (ft_putchar_fd(n - 10 + 'a', fd));
}

int		ft_putnbru(int upper, long unsigned int n, int base)
{
	if (n > ((unsigned int)base - 1))
		return (ft_putnbru(0, n / base, base) + ft_puthexi(n % base, upper));
	else
		return (ft_puthexi(n, upper));
}

int		ft_putnbru_fd(int fd, int upr, long unsigned int n, int b)
{
	if (n > ((unsigned int)b - 1))
		return (ft_putnbru_fd(fd, 0, n / b, b) + ft_puthexi_fd(fd, n % b, upr));
	else
		return (ft_puthexi_fd(n, upr, fd));
}
