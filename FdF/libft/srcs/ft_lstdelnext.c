/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 02:16:03 by bsisic            #+#    #+#             */
/*   Updated: 2014/12/02 02:16:04 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelnext(t_list *alst)
{
	t_list	*tmp;

	tmp = alst->next;
	free(tmp->content);
	alst->next = tmp->next;
	free(tmp);
}
