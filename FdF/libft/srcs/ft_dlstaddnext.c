/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddnext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:11:04 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:11:06 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstaddnext(t_dlist *root, t_dlist *new)
{
	if (new)
	{
		root->next->prev = new;
		new->next = root->next;
		root->next = new;
		new->prev = root;
	}
}
