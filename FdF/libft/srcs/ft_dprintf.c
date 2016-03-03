/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:12:50 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:12:52 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_printpos_fd(int fd, int upper, int nb, int base)
{
	if (nb > 0)
		return (ft_putchar_fd('+', fd) + ft_putnbru_fd(fd, upper, nb, base));
	else
		return (ft_putnbr_fd(nb, fd));
}

static int	ft_printnum(int fd, const char *format, va_list ap, int ispos)
{
	if (*format == 'd' || *format == 'i')
	{
		if (ispos)
			return (ft_printpos_fd(fd, 0, va_arg(ap, int), 10));
		else
			return (ft_putnbr_fd(va_arg (ap, int), fd));
	}
	else if (*format == 'o')
		return (ft_putnbru_fd(fd, 0, va_arg (ap, unsigned int), 8));
	else if (*format == 'u')
		return (ft_putnbru_fd(fd, 0, va_arg (ap, unsigned int), 10));
	else if (*format == 'x')
		return (ft_putnbru_fd(fd, 0, va_arg (ap, unsigned int), 16));
	else if (*format == 'X')
		return (ft_putnbru_fd(fd, 1, va_arg (ap, unsigned int), 16));
	return (0);
}

static int	ft_printarg(int fd, const char *format, va_list ap, int ispos)
{
	if (*format == 's')
		return (ft_putstr_fd(va_arg(ap, char*), fd));
	else if (*format == 'p')
	{
		ft_putstr_fd("0x", fd);
		return (2 + ft_putnbru_fd(fd, 0, va_arg(ap, long unsigned int), 16));
	}
	else if (*format == 'c')
		return (ft_putchar_fd(va_arg(ap, int), fd));
	else if (*format == '%')
		return (ft_putchar_fd('%', fd));
	else if (*format == 'Z')
		return (ft_putchar_fd('Z', fd));
	else
		return (ft_printnum(fd, format, ap, ispos));
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ispos;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		ispos = 0;
		if (*format != '%')
			i += ft_putchar(*format);
		else
		{
			format++;
			i += ft_printarg(fd, format, ap, ispos);
		}
		if (*format)
			format++;
	}
	va_end(ap);
	return (i);
}
