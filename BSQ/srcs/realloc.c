/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:20:27 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:10:37 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}

char		*ft_strcat(char *dst, char *to_add)
{
	int		len_dst;
	int		i;

	len_dst = ft_strlen(dst);
	i = -1;
	while (to_add[++i])
		dst[len_dst + i] = to_add[i];
	dst[len_dst + i] = 0;
	return (dst);
}

char		*ft_reallocat(char *dst, char *to_add)
{
	int		len_dst;
	char	*tmp;
	int		len_to_add;

	len_dst = ft_strlen(dst);
	len_to_add = ft_strlen(to_add);
	tmp = (char *)malloc(sizeof(char) * (len_dst + 1));
	if (!tmp)
	{
		if (dst)
			free(dst);
		return (NULL);
	}
	tmp = ft_strcpy(tmp, dst);
	dst = (char *)malloc(sizeof(char) * (len_dst + len_to_add + 1));
	if (!dst)
	{
		if (tmp)
			free(tmp);
		return (NULL);
	}
	dst = ft_strcpy(dst, tmp);
	dst = ft_strcat(dst, to_add);
	free(tmp);
	return (dst);
}
