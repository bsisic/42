/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:30:00 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:30:01 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	size_t	i;
	size_t	j;

	i = ft_strlen(s);
	j = 0;
	s2 = ft_strnew(i++);
	while (j < i)
	{
		s2[j] = f(j, *s++);
		j++;
	}
	s2[j] = f(j, *s);
	return (s2);
}
