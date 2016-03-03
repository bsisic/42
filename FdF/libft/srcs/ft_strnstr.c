/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:35:38 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:35:40 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	n2;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && n)
	{
		n2 = n;
		i = 0;
		while (haystack[i] == needle[i] && n2)
		{
			i++;
			if (!needle[i])
				return ((char *)haystack);
			if (!haystack[i])
				return (NULL);
			n2--;
		}
		haystack++;
		n--;
	}
	return (NULL);
}
