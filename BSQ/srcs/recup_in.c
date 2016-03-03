/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:20:41 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:10:48 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char		*take_stdin(int fd)
{
	int		nread;
	char	*buff;
	char	*std_in;

	buff = (char *)malloc(sizeof(char) * (BUFF + 1));
	std_in = (char *)malloc(sizeof(char));
	std_in[0] = 0;
	while ((nread = read(fd, buff, BUFF)) && (nread != -1))
	{
		buff[nread] = 0;
		std_in = ft_reallocat(std_in, buff);
		if (!std_in)
			return ("error");
	}
	if (buff)
		free(buff);
	if (nread == -1)
		return ("error");
	return (std_in);
}
