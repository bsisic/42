#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsisic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/05 14:01:08 by bsisic            #+#    #+#              #
#    Updated: 2015/03/05 14:01:10 by bsisic           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = ft_select
LIBDIR = libft/
SRC= select.c	\
	 arrow.c	\
	 term.c		\
	 init.c		\
	 error.c	\
	 print.c	\
	 utils.c	\
	 signal.c

.PHONY = all clean fclean re

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft/
	@$(CC) -c $(SRC) -I. $(CFLAGS)
	@$(CC) -o $(NAME) $(OBJ) -L $(LIBDIR) -lft -L /usr/lib -ltermcap

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)	

re: fclean all

swag: re
	@make clean

.PHONY: all clean fclean re
