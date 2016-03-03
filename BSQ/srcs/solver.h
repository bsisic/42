/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:21:02 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:10:56 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H

typedef struct	s_result
{
	int		place;
	int		size;
}				t_result;

typedef struct	s_infomap
{
	int		len_info_line;
	int		nb_line;
	int		width;
	char	empty;
	char	obstacle;
	char	filled;
}				t_infomap;

void			solve(char *map);
void			print_map_solution(char *map, t_result result, t_infomap info);

#endif
