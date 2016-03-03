/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:18:01 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:08:48 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BUFF 10000*10000
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "map_check.h"
# include "solver.h"

void		ft_putchar(char c);
int			ft_strlen(char *s);
void		ft_putstr(char *s);
void		ft_putendl(char *s);
void		map_error(void);
char		*take_stdin();
int			ft_strcmp(char *s1, char *s2);
char		*ft_reallocat(char *dst, char *to_add);
int			ft_atoi(char *str);
void		av_manage(int ac, char **maps);
void		map_test(int fd);
int			get_width(char *map, int start);
void		ft_putnbr(int n);

#endif
