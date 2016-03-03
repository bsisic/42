/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:02:12 by bsisic            #+#    #+#             */
/*   Updated: 2015/06/03 09:59:34 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		ft_select(int fd)
{
	char	cr[4];

	while (!(cr[0] == 27 && cr[1] == 0 && cr[2] == 0))
	{
		move_cur(cr);
		del_arg(cr);
		end_verif(cr, fd);
		cr[1] = 0;
		cr[2] = 0;
		print_arg(fd);
		read(0, cr, 3);
	}
}

int			main(int ac, char **av)
{
	int		fd;

	fd = 0;
	ft_signal();
	init_glob();
	if (ac < 2)
		print_error(0);
	fd = init_fd(fd);
	create_arg(ac, av);
	init_term();
	g_all.c.cur = g_all.c.start;
	ft_select(fd);
	close_term();
	return (1);
}
