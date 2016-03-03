/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddprev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:11:15 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:11:17 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstaddprev(t_dlist *root, t_dlist *new)
{
	if (new)
	{
		root->prev->next = new;
		new->prev = root->prev;
		root->prev = new;
		new->next = root;
	}
}
