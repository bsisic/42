/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:35:23 by bsisic            #+#    #+#             */
/*   Updated: 2015/01/21 15:35:25 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					sort_by_atime(t_data *data1, t_data *data2)
{
	if (data2->stat->st_atime == data1->stat->st_atime)
		return (sort_by_d_name(data1, data2));
	return (data2->stat->st_atime - data1->stat->st_atime);
}

int					sort_by_size(t_data *data1, t_data *data2)
{
	return (data2->stat->st_size - data1->stat->st_size);
}

int					sort_f(void)
{
	return (1);
}
