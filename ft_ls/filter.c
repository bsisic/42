/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:31:05 by bsisic            #+#    #+#             */
/*   Updated: 2015/01/21 15:31:07 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			lst_filter(t_data *data_lst,
				t_data **errors, t_data **files, t_data **dirs)
{
	t_data		*next;

	while (data_lst)
	{
		next = data_lst->next;
		if (data_lst->type == T_ERROR)
			lst_push_data(data_lst, errors);
		else if (data_lst->type == T_DIR && !g_flags[FLAG_D])
			lst_push_data(data_lst, dirs);
		else
			lst_push_data(data_lst, files);
		data_lst = next;
	}
}

t_data			*lst_exclude(t_data *data_lst, int (*f)(t_data *))
{
	t_data		*new;

	new = NULL;
	while (data_lst)
	{
		if (!f(data_lst))
			lst_push_data(lst_copy_data(data_lst), &new);
		data_lst = data_lst->next;
	}
	return (new);
}

t_data			*lst_include(t_data *data_lst, int (*f)(t_data *))
{
	t_data		*new;

	new = NULL;
	while (data_lst)
	{
		if (f(data_lst))
			lst_push_data(lst_copy_data(data_lst), &new);
		data_lst = data_lst->next;
	}
	return (new);
}
