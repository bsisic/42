/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:02:46 by bsisic            #+#    #+#             */
/*   Updated: 2015/03/05 14:02:47 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int				count_max(t_elem *e)
{
	int			max;
	int			col;

	max = 0;
	col = e->x;
	while (e->prev && (e->prev)->x == col)
		e = e->prev;
	while (e && e->x == col)
	{
		if ((int)ft_strlen(e->value) > max)
			max = (int)ft_strlen(e->value);
		e = e->next;
	}
	return (max + 1);
}

int				ft_tputs(int c)
{
	static int	fd;

	if (fd == 0)
		fd = init_fd(fd);
	ft_putchar_fd(c, fd);
	return (1);
}

int				calc_x(int l, int c, t_elem *e)
{
	int			x;
	int			tmp;

	x = 0;
	while (e->prev)
		e = e->prev;
	while (c > 0)
	{
		x = e->pos_x + count_max(e);
		tmp = 0;
		while (tmp < l)
		{
			e = e->next;
			tmp++;
		}
		c--;
	}
	return (x);
}
