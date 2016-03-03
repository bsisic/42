/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_sol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:18:39 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:09:10 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "dynamic_sol.h"

int				min(int **matrice, int i, int j)
{
	int			min;

	min = matrice[i - 1][j - 1];
	if (matrice[i][j - 1] < min)
		min = matrice[i][j - 1];
	if (matrice[i - 1][j] < min)
		min = matrice[i - 1][j];
	return (min + 1);
}

t_ma			test_max(t_ma ma)
{
	if (ma.tmp[ma.i][ma.j] > ma.tmp[ma.i_max][ma.j_max])
	{
		ma.i_max = ma.i;
		ma.j_max = ma.j;
	}
	return (ma);
}

t_ma			ini(t_ma ma)
{
	ma.i_max = 0;
	ma.j_max = 0;
	return (ma);
}

t_ma			create_maptrice(char *map, t_infomap info)
{
	t_ma		ma;

	ma.trice = (int **)malloc(sizeof(int *) * info.nb_line);
	ma.tmp = (int **)malloc(sizeof(int *) * info.nb_line);
	ma.i = -1;
	ma = ini(ma);
	while (++ma.i < info.nb_line)
	{
		ma.trice[ma.i] = (int *)malloc(sizeof(int) * info.width);
		ma.tmp[ma.i] = (int *)malloc(sizeof(int) * info.width);
		ma.j = -1;
		while (++ma.j < info.width)
		{
			ma.trice[ma.i][ma.j] = (map[ma.j + (ma.i * (info.width + 1))] ==
				info.obstacle) ? 0 : 1;
			if (ma.i == 0 || ma.j == 0)
				ma.tmp[ma.i][ma.j] = ma.trice[ma.i][ma.j];
			else
				ma.tmp[ma.i][ma.j] = (ma.trice[ma.i][ma.j] == 0) ? 0 :
			min(ma.tmp, ma.i, ma.j);
			ma = test_max(ma);
		}
	}
	return (ma);
}

void			dyna_sol(char *map)
{
	t_infomap	info;
	t_ma		ma;

	info.len_info_line = 0;
	while (map[info.len_info_line] != '\n')
		info.len_info_line++;
	info.nb_line = get_waited_line(map, info.len_info_line - 3);
	info.width = get_width(map, info.len_info_line + 1);
	info.empty = map[info.len_info_line - 3];
	info.obstacle = map[info.len_info_line - 2];
	info.filled = map[info.len_info_line - 1];
	ma = create_maptrice(map + info.len_info_line + 1, info);
	print_matrice(ma, info);
}
