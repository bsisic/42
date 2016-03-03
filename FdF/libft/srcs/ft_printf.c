/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:18:31 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:18:33 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_printpos(int upper, int nb, int base)
{
	if (nb > 0)
		return (ft_putchar('+') + ft_putnbru(upper, nb, base));
	else
		return (ft_putnbr(nb));
}

static int	ft_printnum(const char *format, va_list ap, int ispos)
{
	if (*format == 'd' || *format == 'i')
	{
		if (ispos)
			return (ft_printpos(0, va_arg(ap, int), 10));
		else
			return (ft_putnbr(va_arg (ap, int)));
	}
	else if (*format == 'o')
		return (ft_putnbru(0, va_arg (ap, unsigned int), 8));
	else if (*format == 'u')
		return (ft_putnbru(0, va_arg (ap, unsigned int), 10));
	else if (*format == 'x')
		return (ft_putnbru(0, va_arg (ap, unsigned int), 16));
	else if (*format == 'X')
		return (ft_putnbru(1, va_arg (ap, unsigned int), 16));
	return (0);
}

static int	ft_printarg(const char *format, va_list ap, int ispos)
{
	if (*format == 's')
		return (ft_putstr(va_arg(ap, char*)));
	else if (*format == 'p')
	{
		ft_putstr("0x");
		return (2 + ft_putnbru(0, va_arg(ap, long unsigned int), 16));
	}
	else if (*format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (*format == '%')
		return (ft_putchar('%'));
	else if (*format == 'Z')
		return (ft_putchar('Z'));
	else
		return (ft_printnum(format, ap, ispos));
}

int			ft_printf(const char *format, ...)
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
			i += ft_printarg(format, ap, ispos);
		}
		if (*format)
			format++;
	}
	va_end(ap);
	return (i);
}
