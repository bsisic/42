/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 14:20:09 by bsisic            #+#    #+#             */
/*   Updated: 2015/03/04 14:20:10 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static int	check_error(char **arg)
{
	if (arg[3] != NULL)
	{
		ft_putendl("setenv: Too many arguments.");
		return (-1);
	}
	return (0);
}

static char *replace(char **arg, int *j)
{
	int		tot_size;
	char	*replace;

	*j = 1;
	tot_size = (ft_strlen(arg[1]) + ft_strlen(arg[2]) + 2);
	replace = (char *)malloc(sizeof(char) * (tot_size + 1));
	ft_bzero(replace, (tot_size + 1));
	replace = ft_strjoin(arg[1], "=");
	replace = ft_strjoin(replace, arg[2]);
	return (replace);
}

static char	*fill_last(char **arg)
{
	int		i;
	int		j;
	char	*to_cpy;

	i = ft_strlen(arg[0]);
	j = ft_strlen(arg[1]);
	i = i + j;
	if (!(to_cpy = (char *)malloc(sizeof(char) * (i + 2))))
		return (0);
	to_cpy = ft_strjoin(arg[1], "=");
	if (arg[2] != NULL)
		to_cpy = ft_strjoin(to_cpy, arg[2]);
	return (to_cpy);
}

char		**set_env(char **arg, char **env, int j)
{
	char	**new_env;
	int		i;

	if (check_error(arg) == -1)
		return (env);
	i = ft_tablen(env);
	if (!(new_env = (char **)malloc(sizeof(char *) * (i + 2))))
		return (env);
	i = 0;
	while (env[i] != NULL)
	{
		new_env[i] = env[i];
		i++;
	}
	i = 0;
	while (env[i] != 0)
	{
		if (ft_strncmp(arg[1], env[i], ft_strlen(arg[1])) == 0)
			new_env[i] = replace(arg, &j);
		i++;
	}
	if (j != 1)
		new_env[i] = fill_last(arg);
	new_env[i + 1] = NULL;
	return (new_env);
}
