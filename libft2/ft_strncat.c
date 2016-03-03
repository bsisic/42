/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:18:10 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/30 14:25:39 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		len;
	size_t	i;

	len = 0;
	while (s1[len])
		++len;
	i = 0;
	while (i < n && s2[i])
	{
		s1[len + i] = s2[i];
		++i;
	}
	s1[len + i] = 0;
	return (s1);
}
