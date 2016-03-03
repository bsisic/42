#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsisic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/21 15:29:09 by bsisic            #+#    #+#              #
#    Updated: 2015/01/21 15:29:12 by bsisic           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= ft_ls

SRCS	= init.c print.c print_file.c filter.c parse.c ft_ls.c error.c \
		  tools.c more_list.c list.c dir.c file.c data_lst.c sort.c \
		  more_print_file.c more_print.c extended_attr.c permissions.c \
		  more_sort.c columns.c moar_list.c hack.c

OBJS	= $(SRCS:.c=.o)

FLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@gcc -I./libft/includes/ -L./libft/ -lft $(FLAGS) -o $(NAME) $(SRCS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
