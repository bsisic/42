/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:20:26 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/30 14:20:32 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s || (str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	i = start;
	while (i - start < len)
	{
		str[i - start] = s[i];
		++i;
	}
	str[i - start] = 0;
	return (str);
}
