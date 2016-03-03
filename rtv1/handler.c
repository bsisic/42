/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 19:35:06 by bsisic            #+#    #+#             */
/*   Updated: 2015/01/12 19:38:09 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "rtv1.h"

int				get_keypress(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == KEY_QUIT)
		exit(EXIT_SUCCESS);
	return (0);
}

int				get_expose(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->screen.ptr, 0, 0);
	return (0);
}
