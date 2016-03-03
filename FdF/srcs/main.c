/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 01:08:38 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:55:07 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int			ft_put_px(t_coord *e, int x, int y)
{
	mlx_pixel_put(e->mlx, e->win, (x + e->move_x), (y + e->move_y), 0xFFFFFF);
	return (0);
}

void		ft_init_put_px(t_coord *e)
{
	int		index[2];

	index[0] = 0;
	while (index[0] != e->length)
	{
		index[1] = 0;
		while (index[1] != e->width)
		{
			ft_put_px(e, e->val[index[0]][index[1]][0],
					e->val[index[0]][index[1]][1]);
			index[1]++;
		}
		index[0]++;
	}
}

int			ft_init(int **val, int length, int width)
{
	t_coord	e;

	e.move_x = 0;
	e.move_y = 0;
	e.zoom = 0;
	e.t_val = val;
	e.length = length;
	e.width = width;
	e.val = ft_init_coord(e.t_val, e.length, e.width, &e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1920, 1080, "fdf");
	mlx_expose_hook(e.win, &ft_expose_hook, &e);
	e.indice = mlx_key_hook(e.win, &ft_key_hook, &e);
	e.indice = mlx_mouse_hook(e.win, &ft_mouse_hook, &e);
	e.indice = mlx_loop(e.mlx);
	return (0);
}

int			ft_start(int argc, char **argv, char **str, int *ver)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf file1\n");
		return (0);
	}
	if ((ver[0] = open(argv[1], O_RDONLY)) == -1)
	{
		perror(argv[1]);
		return (0);
	}
	if ((ver[1] = ft_open_file(ver[0], str)) == -1)
	{
		perror(argv[1]);
		return (0);
	}
	return (1);
}

int			main(int argc, char *argv[])
{
	char	*str;
	int		ver[2];
	int		length;
	int		width;
	int		**val;

	if (ft_start(argc, argv, &str, ver) == 0)
		return (-1);
	if ((val = ft_create_tab(&str, &length, &width)) == NULL)
	{
		ft_putstr(argv[1]);
		ft_putstr(": Incorrect value in file\n");
		return (0);
	}
	ft_init(val, length, width);
	return (0);
}
