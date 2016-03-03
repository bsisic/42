/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:11:52 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:11:56 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(const char *content)
{
	t_dlist	*root;

	root = (t_dlist *)ft_memalloc(sizeof(t_dlist));
	if (!root)
		return (NULL);
	if (content)
		root->content = ft_strcpy(root->content, content);
	else
		root->content = NULL;
	root->next = root;
	root->prev = root;
	return (root);
}
