/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:32:26 by bsisic            #+#    #+#             */
/*   Updated: 2015/01/21 15:32:27 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_printable_dir(t_data *data_lst)
{
	t_data			*print_lst;

	if (g_flags[FLAG_A])
		print_lst = data_lst;
	else if (g_flags[FLAG_AA])
		print_lst = lst_exclude(data_lst, &is_tree_dir);
	else
		print_lst = lst_exclude(data_lst, &is_hidden);
	print_data_lst(print_lst);
	if (!g_flags[FLAG_A])
		lst_pseudo_free(print_lst);
}
