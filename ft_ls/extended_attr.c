/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extended_attr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:30:03 by bsisic            #+#    #+#             */
/*   Updated: 2015/01/21 15:30:05 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				has_extended_attr(char *path)
{
	int			count;

	count = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	if (count > 0)
		return (1);
	else
		return (0);
}
