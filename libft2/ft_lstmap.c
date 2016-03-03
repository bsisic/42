/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 14:01:17 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/30 14:01:26 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*fraiche;
	t_list		*cursor;
	t_list		*tmp;

	if (lst && f)
	{
		tmp = f(lst);
		if (!(fraiche = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		cursor = fraiche;
		while (lst->next)
		{
			tmp = f(lst->next);
			if (!(fraiche->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			lst = lst->next;
			fraiche = fraiche->next;
		}
		return (cursor);
	}
	return (NULL);
}
