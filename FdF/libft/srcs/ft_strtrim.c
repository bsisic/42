/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:36:39 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:36:41 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (ft_strlen(s))
		i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	str = ft_strnew(i);
	if (str)
	{
		while (i)
		{
			str[i] = s[i];
			i--;
		}
		str[i] = s[i];
	}
	return (str);
}
