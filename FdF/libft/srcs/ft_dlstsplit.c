/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:12:39 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:12:41 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlist	*ft_dlstsplit(const char *s, char c)
{
	t_dlist	*root;
	char	*tmp;
	size_t	i;

	i = 0;
	root = ft_dlstnew(NULL);
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] && s[i] != c)
			i++;
		if (i > 0)
		{
			tmp = ft_strndup(s, i);
			ft_dlstaddprev(root, ft_dlstnew(tmp));
			free(tmp);
		}
		s += i;
	}
	return (root);
}
