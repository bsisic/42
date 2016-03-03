/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:01:42 by bsisic            #+#    #+#             */
/*   Updated: 2015/03/05 14:01:44 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		print_error(int e)
{
	if (e == 0)
		ft_putendl_fd("usage: ft_select [arg ...]", 2);
	else if (e == 1)
		ft_putendl_fd("error: environment error", 2);
	else if (e == 2)
	{
		close_term();
		ft_putendl_fd("open failed", 2);
	}
	else if (e == 3)
		close_term();
	exit(1);
}
