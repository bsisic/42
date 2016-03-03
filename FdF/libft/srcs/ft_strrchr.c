/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:35:47 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:35:49 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;

	s2 = NULL;
	while (*s)
	{
		if (*s == c)
			s2 = (char *)s;
		s++;
	}
	if (*s == c)
		s2 = (char *)s;
	return (s2);
}
