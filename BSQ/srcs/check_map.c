/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:18:27 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:09:00 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				check_first_line(char *map)
{
	int			lenum;
	int			i;

	lenum = len_num(map);
	i = lenum;
	if (map[i] == '\n' || map[i] == map[i + 1] || map[i] == map[i + 2])
		return (-1);
	if (map[i + 1] == '\n' || map[i + 1] == map[i + 2])
		return (1);
	if (map[i + 2] == '\n')
		return (1);
	if (map[i + 3] != '\n')
		return (-1);
	return (lenum);
}

int				checking_char(char *map, char to_test, int start)
{
	int			i;

	i = -1;
	while (++i < 4)
	{
		if (i != 2 && to_test == map[start + i])
			return (0);
	}
	return (1);
}

int				check_map_char(char *map, int start)
{
	int			i;

	i = start + 3;
	while (map[++i])
	{
		if (checking_char(map, map[i], start))
			return (1);
	}
	return (0);
}

int				checkif_numb(char *map, int end)
{
	int			i;

	i = -1;
	while (++i < end)
	{
		if (!(map[i] >= '0' && map[i] <= '9'))
			return (1);
	}
	return (0);
}

int				check_map(char *map)
{
	int			start;
	int			num_len;

	if (!(num_len = len_num(map)))
		return (1);
	if (checkif_numb(map, num_len))
		return (1);
	if ((start = check_first_line(map)) == -1)
		return (1);
	if (check_map_char(map, start))
		return (1);
	if (minimun_length(map))
		return (1);
	if (check_map_cperline_lines(map, start))
		return (1);
	return (0);
}
