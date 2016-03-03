/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:20:11 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/30 14:20:16 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t a;
	size_t b;

	a = 0;
	b = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[a])
	{
		while (s1[a + b] && s1[a + b] == s2[b])
			b++;
		if (!s2[b])
			return ((char *)s1 + a);
		else
			b = 0;
		a++;
	}
	return (NULL);
}
