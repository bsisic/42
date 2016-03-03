/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:01:49 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/30 14:01:57 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	size_t	i;
	void	*ptr;
	char	*tmp;

	if ((ptr = malloc(size)) == NULL)
		return (NULL);
	i = -1;
	tmp = (char *)ptr;
	while (++i < size)
		tmp[i] = 0;
	return (ptr);
}
