/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:01:51 by bsisic            #+#    #+#             */
/*   Updated: 2015/03/05 14:01:53 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int			init_fd(int fd)
{
	fd = open(ttyname(fd), O_RDWR | O_NONBLOCK);
	return (fd);
}

void		create_arg(int ac, char **av)
{
	int		i;
	t_elem	*e;
	t_elem	*prev;

	i = 1;
	while (i < ac)
	{
		e = (t_elem *)malloc(sizeof(t_elem));
		e->value = ft_strdup(av[i]);
		e->sel = 0;
		prev = g_all.c.end;
		if (g_all.c.start)
			prev->next = e;
		else
			g_all.c.start = e;
		e->prev = prev;
		e->next = NULL;
		g_all.c.end = e;
		i++;
	}
	set_coor();
}

void		init_glob(void)
{
	g_all.c.start = NULL;
	g_all.c.end = NULL;
	g_all.c.cur = NULL;
}
