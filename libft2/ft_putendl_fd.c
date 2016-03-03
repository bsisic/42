/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:10:43 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/30 14:10:50 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putendl_fd(char const *s, int fd)
{
	int		len;

	len = 0;
	while (s[len])
		++len;
	write(fd, s, len);
	write(fd, "\n", 1);
}
