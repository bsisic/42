/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:29:14 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:29:15 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str)
	{
		str = ft_strcpy(str, s1);
		str += ft_strlen(s1);
		str = ft_strcpy(str, s2);
		str -= ft_strlen(s1);
	}
	return (str);
}
