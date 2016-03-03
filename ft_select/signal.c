/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsisic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 14:02:37 by bsisic            #+#    #+#             */
/*   Updated: 2015/03/05 14:02:38 by bsisic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void			ft_signal(void)
{
	signal(SIGWINCH, resize);
	signal(SIGTSTP, stop);
	signal(SIGCONT, restart);
	signal(SIGINT, end);
}

void			resize(int sig)
{
	static int	fd;

	(void)sig;
	set_coor();
	if (fd == 0)
		fd = init_fd(fd);
	print_arg(fd);
}

void			stop(int sig)
{
	char		cp[2];

	cp[0] = 032;
	cp[1] = 0;
	(void)sig;
	close_term();
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

void			restart(int sig)
{
	static int	fd;

	(void)sig;
	start_term();
	signal(SIGTSTP, stop);
	if (fd == 0)
		fd = init_fd(fd);
	print_arg(fd);
}

void			end(int sig)
{
	(void)sig;
	close_term();
	exit(1);
}
