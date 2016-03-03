/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:38:50 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:38:52 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static t_read	*ft_freeread(t_read *red, t_read *prev, t_read **start)
{
	if (!prev)
		*start = red->next;
	else
		prev->next = red->next;
	free(red->read);
	free(red);
	if (!prev)
		return (*start);
	else
		return (prev->next);
}

static t_read	*ft_newread(int fd)
{
	t_read	*red;
	void	*tmp;
	int		ret;

	if (!(red = (t_read *)malloc(sizeof(t_read))))
		return (NULL);
	if (!(tmp = malloc(sizeof(char) * BUFF_SIZE)))
	{
		free(red);
		return (NULL);
	}
	if ((ret = read(fd, tmp, BUFF_SIZE)) < 0)
	{
		free(red);
		free(tmp);
		return (NULL);
	}
	red->read = (char *)tmp;
	red->fd = fd;
	red->size = ret;
	red->next = NULL;
	red->ind = 0;
	return (red);
}

static int		ft_print(int n, t_read **tab, t_read **s, char **l)
{
	char	*tmpstr;
	int		ind;

	if (!tab[0])
		return (-1);
	ind = (tab[0])->ind;
	if (n == -1 || !(tmpstr = (char *)malloc(sizeof(char) * (n + 1))))
		return (-1);
	*l = tmpstr;
	while (n--)
	{
		*tmpstr++ = (tab[0])->read[ind++];
		if (ind == (tab[0])->size)
		{
			tab[0] = ft_freeread(tab[0], tab[1], s);
			ind = 0;
		}
	}
	*tmpstr = 0;
	if (!tab[0] || (ind == tab[0]->size && tab[0]->size < BUFF_SIZE))
		return (0);
	tab[0]->ind = ind + 1;
	if (tab[0]->ind == tab[0]->size)
		tab[0] = ft_freeread(tab[0], tab[1], s);
	return (1);
}

static int		ft_findendl(int fd, t_read *red)
{
	int		ind;
	int		size;
	t_read	*tmplst;

	size = 0;
	ind = red->ind;
	while (red->read[ind] != '\n' && ind < red->size)
	{
		ind++;
		size++;
		if (ind == red->size && red->size == BUFF_SIZE)
		{
			if (!(tmplst = ft_newread(fd)))
				return (-1);
			tmplst->next = red->next;
			red->next = tmplst;
			red = tmplst;
			ind = 0;
		}
	}
	return (size);
}

int				get_next_line(int fd, char **line)
{
	static t_read	*start = NULL;
	t_read			*red;
	t_read			*prevtmp;
	t_read			*tab[2];

	if (fd < 0)
		return (-1);
	prevtmp = NULL;
	if (!start)
		start = ft_newread(fd);
	red = start;
	while (red->fd != fd)
	{
		if (!(red->next))
			red->next = ft_newread(fd);
		prevtmp = red;
		red = red->next;
	}
	if (!red || !start)
		return (-1);
	tab[0] = red;
	tab[1] = prevtmp;
	return (ft_print(ft_findendl(fd, red), tab, &start, line));
}
