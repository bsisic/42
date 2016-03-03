/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:20:09 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:10:16 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "dynamic_sol.h"

void			print_matrice(t_ma ma, t_infomap info)
{
	int			size;

	size = ma.tmp[ma.i_max][ma.j_max];
	ma.i = -1;
	while (++ma.i < info.nb_line)
	{
		ma.j = -1;
		while (++ma.j < info.width)
		{
			if ((ma.i > (ma.i_max - size) && ma.i <= ma.i_max) && (ma.j >
				(ma.j_max - size) && ma.j <= ma.j_max))
				ft_putchar(info.filled);
			else if (ma.trice[ma.i][ma.j] == 1)
				ft_putchar(info.empty);
			else
				ft_putchar(info.obstacle);
		}
		ft_putchar('\n');
	}
}
