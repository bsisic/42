/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 01:03:34 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 01:03:35 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <mlx.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_coord
{
	int			***val;
	int			length;
	int			width;
	int			indice;
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			max;
	int			move_x;
	int			move_y;
	int			move_y_z;
	int			move_x_z;
	int			zoom;
	int			**t_val;
	int			sqr_x;
	int			sqr_y;
}				t_coord;

int				ft_start(int argc, char **argv, char **str, int *ver);
int				ft_open_file(int fd, char **file);
int				*ft_atoi_line(char *str, int *i);
int				**ft_create_tab(char **str, int *i, int *len);
int				ft_init(int **val, int length, int width);
int				ft_key_hook(int keycode, t_coord *e);
int				ft_key_h(int keycode, t_coord *e);
int				***ft_init_coord(int **val, int length, int width, t_coord *e);
void			ft_init_c(int *x, int *y, int *index, int **val);
int				ft_put_px(t_coord *e, int x, int y);
void			ft_init_put_px(t_coord *e);
void			ft_set_coord(int *x, int *start, int nb1, int nb2);
void			ft_draw_line_x(t_coord *e, int i, int j);
void			ft_draw_line_y(t_coord *e, int i, int j);
void			ft_init_line_x(t_coord *e);
void			ft_init_line_y(t_coord *e);
int				ft_expose_hook(t_coord *e);
int				ft_mouse_hook(int button, int x, int y, t_coord *e);
void			ft_put_help(t_coord *e, int m_x, int m_y);
void			ft_write_op(t_coord *e);
void			ft_verif_value(int **val, int length, int width);

#endif
