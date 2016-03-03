/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:16:58 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:17:00 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	while (n)
	{
		*(unsigned char *)s1 = *(unsigned char *)s2;
		if (*(unsigned char *)s2 == (unsigned char)c)
		{
			s1 = (unsigned char *)s1 + 1;
			return (s1);
		}
		s2 = (unsigned char *)s2 + 1;
		s1 = (unsigned char *)s1 + 1;
		n--;
	}
	return (NULL);
}
