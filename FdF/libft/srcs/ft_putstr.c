/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:26:31 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:26:33 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putstr(const char *s)
{
	if (s)
		return (write(1, s, ft_strlen(s)));
	else
		return (write(1, "(null)", 6));
}
