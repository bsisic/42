/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:29:49 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:29:50 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s2;
	size_t	len;
	size_t	j;

	len = ft_strlen(s);
	j = 0;
	s2 = ft_strnew(len);
	while (j < len)
	{
		s2[j] = f(*s++);
		j++;
	}
	s2[j] = f(*s);
	return (s2);
}
