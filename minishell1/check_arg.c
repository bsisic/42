/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:19:04 by bsisic            #+#    #+#             */
/*   Updated: 2015/03/04 14:19:06 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void		close_shell(void)
{
	ft_putendl("exit");
	exit(0);
}

static char	**check_env(char **av, char **env)
{
	if (ft_strcmp(av[0], "setenv") == 0)
	{
		if (av[1] == NULL)
			print_tab(env);
		else
			env = set_env(av, env, 3);
	}
	else if (ft_strcmp(av[0], "env") == 0 && av[1] == NULL)
		print_tab(env);
	else if (ft_strcmp(av[0], "unsetenv") == 0)
	{
		if (av[1] == NULL)
			ft_putendl("unsetenv: Too few arguments.");
		else
			env = unset_env(env, av);
	}
	return (env);
}

char		**check_arg(char **av, char **env)
{
	env = check_env(av, env);
	if (ft_strcmp(av[0], "cd") == 0)
		ft_cd(av, env);
	else if (ft_strcmp(av[0], "exit") == 0)
		close_shell();
	else
		ft_exec(av, env);
	return (env);
}
