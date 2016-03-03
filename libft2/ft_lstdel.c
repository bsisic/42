/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 13:59:45 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/30 13:59:56 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list			*tmp;
	t_list			*tmp2;

	if (!alst || !*alst || !del)
		return ;
	tmp = *alst;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp2->next;
	}
	*alst = NULL;
}
