/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:10:41 by bsisic            #+#    #+#             */
/*   Updated: 2015/03/05 14:10:43 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		init_term(void)
{
	t_elem	*e;
	char	*name;

	e = g_all.c.start;
	name = getenv("TERM");
	if (name == NULL)
		print_error(1);
	tgetent(NULL, name);
	tcgetattr(0, &(g_all.term));
	start_term();
}

void		start_term(void)
{
	g_all.term.c_lflag &= ~(ICANON | ECHO);
	g_all.term.c_lflag |= (ISIG);
	g_all.term.c_cc[VMIN] = 1;
	g_all.term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &(g_all.term));
	tputs(tgetstr("ti", NULL), 1, ft_tputs);
	tputs(tgetstr("vi", NULL), 1, ft_tputs);
}

void		close_term(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_tputs);
	tputs(tgetstr("te", NULL), 1, ft_tputs);
	tputs(tgetstr("ve", NULL), 1, ft_tputs);
	g_all.term.c_lflag |= (ICANON | ECHO | ISIG);
	g_all.term.c_cc[VMIN] = 1;
	g_all.term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &(g_all.term));
}
