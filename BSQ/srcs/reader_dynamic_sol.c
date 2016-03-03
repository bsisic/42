/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_dynamic_sol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:20:18 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:10:25 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "dynamic_sol.h"

void		map_test(int fd)
{
	char	*std_in;

	std_in = take_stdin(fd);
	if (!ft_strcmp(std_in, "error"))
		map_error();
	else
	{
		if (check_map(std_in))
			map_error();
		else
			dyna_sol(std_in);
		if (std_in)
			free(std_in);
	}
}

void		av_manage(int ac, char **maps)
{
	int		i;
	int		fd;

	i = -1;
	while (++i < ac)
	{
		fd = open(maps[i], O_RDONLY);
		map_test(fd);
		close(fd);
	}
}
