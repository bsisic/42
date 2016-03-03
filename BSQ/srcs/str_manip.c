/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:21:11 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:11:05 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			ft_strlen(char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int			ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = -1;
	while (s1[++i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
	}
	if (s1[i] != s2[i])
		return (1);
	return (0);
}

int			get_width(char *map, int start)
{
	int		i;

	i = 0;
	while (map[i + start] != '\n')
		i++;
	return (i);
}
