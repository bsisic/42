/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 20:33:24 by bsisic            #+#    #+#             */
/*   Updated: 2015/02/14 20:49:26 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_pile
{
	int nb; // donnees
	struct s_pile *prec; //pointeur sur element precedent de la pile
}				t_pile;

#endif
