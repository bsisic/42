/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:19:19 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/30 14:27:07 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[a] && a < n)
	{
		while (s1[a + b] && s1[a + b] == s2[b] && (a + b) < n)
			b++;
		if (!s2[b])
			return ((char *)s1 + a);
		else
			b = 0;
		a++;
	}
	return (NULL);
}
