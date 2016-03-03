/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:19:03 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/30 14:19:09 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	if ((str = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	i = -1;
	while (++i < size + 1)
		str[i] = '\0';
	return (str);
}
