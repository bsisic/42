/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_map_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:21:20 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:11:15 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				len_num(char *map)
{
	int			i;

	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	return (i - 3);
}

int				minimun_length(char *map)
{
	int			i;

	i = 0;
	while (map[i] && map[i] != '\n')
		i++;
	if (map[i] == 0 || map[i + 1] == 0 || map[i + 1] == '\n')
		return (1);
	return (0);
}

int				get_waited_line(char *map, int end)
{
	int			nb_line;
	char		*nb_ch;
	int			i;

	nb_ch = (char *)malloc(sizeof(char) * (end + 1));
	i = -1;
	while (++i < end)
		nb_ch[i] = map[i];
	nb_ch[i] = 0;
	nb_line = ft_atoi(nb_ch);
	if (nb_ch)
		free(nb_ch);
	return (nb_line);
}

int				check_map_cperline_lines(char *map, int start)
{
	int			i;
	int			c_per_line;
	int			c_last_line;
	int			true_line;
	int			waited_line;

	waited_line = get_waited_line(map, start);
	true_line = 0;
	i = start + 3;
	c_per_line = 1;
	while (map[++i] && true_line <= waited_line)
	{
		if (map[i] == '\n')
		{
			if (true_line > 0 && c_per_line != c_last_line)
				return (1);
			c_last_line = c_per_line;
			c_per_line = 0;
			true_line++;
		}
		c_per_line++;
	}
	if (true_line != waited_line)
		return (1);
	return (0);
}
