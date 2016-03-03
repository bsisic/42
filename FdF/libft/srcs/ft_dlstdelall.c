/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:11:26 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:49:59 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelall(t_dlist *dlst)
{
	if (dlst)
	{
		while (dlst->next != dlst)
			ft_dlstdelone(dlst->next);
		ft_dlstdelone(dlst);
	}
}
