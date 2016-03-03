/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 19:34:54 by bsisic            #+#    #+#             */
/*   Updated: 2015/01/12 19:37:49 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "rtv1.h"

void		pxl_putimg(t_mlx *mlx, int x, int y, u_int color)
{
	int		i;
	int		dest;
	u_int	new_color;

	new_color = mlx_get_color_value(mlx->ptr, color);
	dest = y * mlx->screen.sline + x * mlx->screen.bpp;
	i = -1;
	while (++i < mlx->screen.bpp)
	{
		if (mlx->screen.endian == 0)
			mlx->screen.data[dest + i] = new_color >> (i << 3) & 0xFF;
		else
			mlx->screen.data[dest + i] = new_color
				>> (mlx->screen.bpp - ((i + 1) << 3)) & 0xFF;
	}
}
