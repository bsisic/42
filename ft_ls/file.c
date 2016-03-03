/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:30:13 by bsisic            #+#    #+#             */
/*   Updated: 2015/01/21 15:30:14 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					is_hidden(t_data *file)
{
	if (file->d_name[0] == '.' && file->d_name[1] != '/')
		return (1);
	return (0);
}

int					is_dir(t_data *file)
{
	if (file->type == T_DIR)
		return (1);
	return (0);
}

int					is_printable_dir(t_data *file)
{
	if (!is_hidden(file)
		|| g_flags[FLAG_A]
		|| is_tree_dir(file)
		|| g_settings[S_CALL] == 1)
		return (1);
	return (0);
}

int					is_explorable_dir(t_data *file)
{
	if (file->type == T_DIR && !is_tree_dir(file))
		return (1);
	return (0);
}

int					is_tree_dir(t_data *file)
{
	if ((file->d_name[0] == '.' && file->d_name[1] == '\0')
		|| (file->d_name[0] == '.'
		&& file->d_name[1] == '.' && file->d_name[2] == '\0'))
		return (1);
	return (0);
}
