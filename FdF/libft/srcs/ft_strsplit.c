/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:35:59 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:36:01 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_fill(const char *s, char c, char **tab)
{
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > j)
		{
			tab[count] = ft_strsub(s, j, i - j);
			count++;
		}
	}
	tab[count] = '\0';
}

static int	ft_count(const char *s, char c)
{
	int		i;
	int		line;

	i = 0;
	line = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c || i == 0) && s[i + 1] != c && s[i + 1] != '\0')
			line++;
		i++;
	}
	return (line);
}

char		**ft_strsplit(char const *s, char c)
{
	int		line;
	char	**tab;

	line = 0;
	line = ft_count(s, c);
	tab = malloc(sizeof(char**) * (line + 1));
	ft_fill(s, c, tab);
	return (tab);
}
