/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 01:06:31 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 01:06:33 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define BUFF_SIZE 4096

int				ft_open_file(int fd, char **file)
{
	ssize_t		ret;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	*file = malloc(sizeof(**file) * 1);
	**file = '\0';
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(*file, buff);
		free(*file);
		*file = tmp;
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int				*ft_atoi_line(char *str, int *i)
{
	int			*line;
	char		**tab;

	tab = ft_strsplit(str, ' ');
	*i = 0;
	while (tab[*i])
		*i += 1;
	if (!(line = malloc(sizeof(*line) * (*i + 1))))
		return (NULL);
	*i = 0;
	while (tab[*i])
	{
		line[*i] = ft_atoi(tab[*i]);
		*i += 1;
	}
	return (line);
}

int				**ft_create_tab(char **str, int *i, int *len)
{
	int			**tab;
	char		**tab_str;

	if ((tab_str = ft_strsplit(*str, '\n')) == NULL)
		return (NULL);
	free(*str);
	*i = 0;
	while (tab_str[*i])
		*i += 1;
	if (!(tab = malloc(sizeof(*tab) * (*i + 1))))
		return (NULL);
	*i = 0;
	while (tab_str[*i])
	{
		if ((tab[*i] = ft_atoi_line(tab_str[*i], len)) == NULL)
			return (NULL);
		tab[*i] = ft_atoi_line(tab_str[*i], len);
		*i += 1;
	}
	return (tab);
}
