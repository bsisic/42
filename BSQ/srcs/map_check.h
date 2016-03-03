/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 16:19:40 by mmisere           #+#    #+#             */
/*   Updated: 2015/07/30 22:09:59 by mmisere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECK_H
# define MAP_CHECK_H

int			check_map_cperline_lines(char *map, int start);
int			minimun_length(char *map);
int			len_num(char *map);
int			check_map(char *map);
int			get_waited_line(char *map, int end);

#endif
