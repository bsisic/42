/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_sol.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:18:49 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:09:19 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNAMIC_SOL_H
# define DYNAMIC_SOL_H

typedef struct	s_ma
{
	int		**trice;
	int		**tmp;
	int		i;
	int		j;
	int		i_max;
	int		j_max;
}				t_ma;

void			dyna_sol(char *map);
void			print_matrice(t_ma ma, t_infomap info);

#endif
