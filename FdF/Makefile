#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsisic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/02 00:52:20 by bsisic            #+#    #+#              #
#    Updated: 2014/12/02 00:52:24 by bsisic           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= fdf
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -ansi -pedantic -Wshadow -Wno-missing-noreturn \
			-Wno-padded -Wno-unreachable-code -Wredundant-decls \
			-Wmissing-declarations
LFLAGS	= -L./libft -lft -L/usr/X11/lib -lXext -lX11 -lmlx
SRC_DIR	= ./srcs/
SRC		= drawline.c get_line.c hooks.c helper.c init.c main.c
VPATH	= $(SRC_DIR)
INC		= -I./includes -I./libft/includes
O_DIR	= ./obj
OBJ		= $(addprefix $(O_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	
	@echo "\033[1;34m"
	@echo "__________________________________"
	@echo "|                                |"
	@echo "|  _|_|_|_|  _|_|_|    _|_|_|_|  |"
	@echo "|  _|        _|    _|  _|        |"
	@echo "|  _|_|_|    _|    _|  _|_|_|    |"
	@echo "|  _|        _|    _|  _|        |"
	@echo "|  _|        _|_|_|    _|        |"
	@echo "|                                |"
	@echo "|_____________________by bsisic__|"
	
	@make -C libft
	@echo "Linking binary."
	@$(CC) -o $(NAME) $^ $(LFLAGS)

$(O_DIR)/%.o: %.c
	@mkdir -p $(O_DIR)
	@printf "."
	@$(CC) $(CFLAGS) -c $< -I ./includes -o $@

clean:
	@echo "Deleting obj files."
	@rm -f $(OBJ)

fclean: clean
	@echo "Deleting fdf."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
