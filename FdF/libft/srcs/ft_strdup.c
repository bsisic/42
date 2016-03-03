/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:28:15 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:28:17 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*s2;

	i = ft_strlen(s);
	s2 = malloc(sizeof(*s) * (i + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	s2 = ft_strcpy(s2, s);
	return (s2);
}
