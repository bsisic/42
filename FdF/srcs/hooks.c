/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 01:07:34 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 01:07:36 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_keyhook(int keycode, t_coord *e)
{
	if (keycode == 65453)
	{
		e->zoom -= 5;
		if (e->zoom == -35)
			e->zoom = -30;
		mlx_clear_window(e->mlx, e->win);
		e->val = ft_init_coord(e->t_val, e->length, e->width, e);
		ft_expose_hook(e);
	}
}

int			ft_expose_hook(t_coord *e)
{
	ft_init_put_px(e);
	ft_init_line_x(e);
	ft_init_line_y(e);
	ft_write_op(e);
	return (0);
}

int			ft_key_h(int keycode, t_coord *e)
{
	if (keycode == 65362)
	{
		e->move_y = e->move_y - 30;
		mlx_clear_window(e->mlx, e->win);
		ft_expose_hook(e);
	}
	if (keycode == 65451)
	{
		e->zoom = e->zoom + 5;
		if (e->zoom == 100)
			e->zoom = 95;
		e->move_x_z += 15;
		e->move_y_z += 15;
		mlx_clear_window(e->mlx, e->win);
		e->val = ft_init_coord(e->t_val, e->length, e->width, e);
		ft_expose_hook(e);
	}
	ft_keyhook(keycode, e);
	return (0);
}

int			ft_key_hook(int keycode, t_coord *e)
{
	if (keycode == 65307)
		exit (0);
	if (keycode == 65363)
	{
		e->move_x = e->move_x + 30;
		mlx_clear_window(e->mlx, e->win);
		ft_expose_hook(e);
	}
	if (keycode == 65361)
	{
		e->move_x = e->move_x - 30;
		mlx_clear_window(e->mlx, e->win);
		ft_expose_hook(e);
	}
	if (keycode == 65364)
	{
		e->move_y = e->move_y + 30;
		mlx_clear_window(e->mlx, e->win);
		ft_expose_hook(e);
	}
	ft_key_h(keycode, e);
	return (0);
}

int			ft_mouse_hook(int button, int x, int y, t_coord *e)
{
	(void)x;
	(void)y;
	if (button == 1 || button == 5)
	{
		e->zoom = e->zoom + 5;
		if (e->zoom == 100)
			e->zoom = 95;
		mlx_clear_window(e->mlx, e->win);
		e->val = ft_init_coord(e->t_val, e->length, e->width, e);
		ft_expose_hook(e);
	}
	if (button == 3 || button == 4)
	{
		e->zoom -= 5;
		if (e->zoom == -35)
			e->zoom = -30;
		mlx_clear_window(e->mlx, e->win);
		e->val = ft_init_coord(e->t_val, e->length, e->width, e);
		ft_expose_hook(e);
	}
	return (0);
}
