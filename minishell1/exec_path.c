/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:19:12 by bsisic            #+#    #+#             */
/*   Updated: 2015/03/04 14:19:14 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	exec_path(char *bin_path, char **arg)
{
	char *to_send;

	to_send = ft_strjoin(bin_path, "/");
	to_send = ft_strjoin(to_send, arg[0]);
	execve(to_send, arg, NULL);
}

void	exec_arg(char **arg, char **env)
{
	int		i;
	int		bwait[1];
	pid_t	father;

	i = search_line(env);
	if (i == -1)
		return ;
	father = fork();
	i = 0;
	if (father > 0)
		wait(bwait);
	if (father == 0)
	{
		execve(arg[0], arg, NULL);
		print_errors(arg);
		exit(0);
	}
}
