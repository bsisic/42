/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:16:26 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:16:28 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dest;

	dest = ft_lstnew(lst->content, lst->content_size);
	if (!dest)
		return (NULL);
	f(lst);
	if (lst->next)
		dest->next = ft_lstmap(lst->next, f);
	return (dest);
}
