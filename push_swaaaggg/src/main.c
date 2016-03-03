/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 20:32:21 by bsisic            #+#    #+#             */
/*   Updated: 2015/02/14 20:57:51 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/push_swap.h>
#include <stdio.h>
int main(int ac, char **av)
{
	t_pile *x;

	x = NULL;
	if (ac < 2)
		printf("error\n");
	while (av != NULL)
		printf("%d", &x);
	return (0);
}
