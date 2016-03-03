/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:11:36 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:11:43 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlstdelone(t_dlist *dlst)
{
	if (dlst)
	{
		dlst->next->prev = dlst->prev;
		dlst->prev->next = dlst->next;
		if (dlst->content)
			free(dlst->content);
		free(dlst);
		dlst = NULL;
	}
}
