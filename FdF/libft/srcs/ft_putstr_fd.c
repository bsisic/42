/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:26:46 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:26:47 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putstr_fd(const char *s, int fd)
{
	if (s)
		return (write(fd, s, ft_strlen(s)));
	else
		return (write(fd, "(null)", 6));
}
