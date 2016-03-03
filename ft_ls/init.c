/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:31:41 by bsisic            #+#    #+#             */
/*   Updated: 2015/01/21 15:31:42 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					initialize(t_data *arg_lst)
{
	t_data		*errors;
	t_data		*files;
	t_data		*dirs;

	errors = NULL;
	files = NULL;
	dirs = NULL;
	lst_filter(arg_lst, &errors, &files, &dirs);
	e_args_error(errors);
	print_data_lst(files);
	print_dirs(dirs);
	lst_free(errors);
	lst_free(files);
	return (0);
}
