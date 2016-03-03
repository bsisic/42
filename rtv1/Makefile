#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsisic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/12 19:34:17 by bsisic            #+#    #+#              #
#    Updated: 2015/01/13 20:01:12 by bsisic           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=		rtv1

SRCS=		main.c		\
			calc.c		\
			light.c		\
			shadow.c	\
			colors.c	\
			rotate.c	\
			inter_obj.c	\
			draw.c		\
			list.c		\
			string.c	\
			handler.c

OBJS=		$(SRCS:%.c=%.o)

LIB=		-L/usr/X11/lib -lmlx -lXext -lX11 -lm

CFLAGS=		-Wall -Wextra -Werror -I/usr/X11/include/

CC=			gcc

RM=			rm -f

all: $(NAME)

$(NAME):	$(OBJS)
			@echo "\033[34m Compilation : \033[32m OK ! \033[0m"
			@$(CC) -o $(NAME) $(OBJS) $(LIB)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
