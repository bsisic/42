#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmisere <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/30 15:54:51 by mmisere           #+#    #+#              #
#    Updated: 2015/07/30 16:14:38 by mmisere          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY:		all clean fclean re

SRC = 		srcs/check_map.c srcs/dynamic_sol.c srcs/reader_dynamic_sol.c\
			srcs/ft_atoi_putnbr.c srcs/main_bsq.c srcs/print_matrice.c\
			srcs/recup_in.c srcs/str_manip.c srcs/str_map_check.c srcs/error.c\
			srcs/print.c srcs/realloc.c

NAME = 		bsq

FLAGS = 	-Wall -Wextra -Werror

all:		default

default:
			@gcc $(FLAGS) $(SRC) -o $(NAME)
			@echo "\033[34mCOMPILATION : \033[45mOK\033[0m"
			@echo "\033[31m\033[1m\033[4m\033[5m\033[7mBSQ by mmisere&qcharbit\033[0m"
			@echo "\033[1mdo : \033[34m./bsq \033[1mmap/map00\033[0m"
clean:
	@rm -f $(OBJ)
	@echo "\033[34mDeleting \033[45mOBJ\033[0m"
fclean: clean
	@rm -f $(NAME)
	@echo "\033[34mDeleting \033[45mBSQ\033[0m"
re: fclean all
