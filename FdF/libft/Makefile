#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsisic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/02 00:55:53 by bsisic            #+#    #+#              #
#    Updated: 2014/12/02 00:56:13 by bsisic           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -ansi -pedantic -Wshadow -Wno-missing-noreturn \
			-Wno-padded -Wno-unreachable-code -Wredundant-decls \
			-Wmissing-declarations
SRC_DIR	= ./srcs/
SRC		= ft_atoi.c ft_isprint.c ft_memmove.c ft_strcmp.c ft_strndup.c \
			ft_bzero.c ft_isspace.c ft_memset.c ft_strcpy.c ft_strnequ.c \
			ft_dlstaddnext.c ft_itoa.c ft_printf.c ft_strdel.c ft_strnew.c \
			ft_dlstaddprev.c ft_lstaddnext.c ft_putchar.c ft_strdup.c \
			ft_strnstr.c ft_dlstdelall.c ft_lstdelall.c ft_putchar_fd.c \
			ft_strequ.c ft_strrchr.c ft_dlstdelone.c ft_lstdelnext.c \
			ft_putendl.c ft_striter.c ft_strsplit.c ft_dlstnew.c ft_lstiter.c \
			ft_putendl_fd.c ft_striteri.c ft_strstr.c ft_dlstnext.c \
			ft_lstmap.c ft_putnbr.c ft_strjoin.c ft_strsub.c ft_dlstprev.c \
			ft_lstnew.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
			ft_dlstsplit.c ft_memalloc.c ft_puts.c ft_strlen.c ft_tolower.c \
			ft_dprintf.c ft_memccpy.c ft_putstr.c ft_strmap.c ft_toupper.c \
			ft_isalnum.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c \
			getnextline.c ft_isalpha.c ft_memcmp.c ft_strcat.c ft_strncat.c \
			ft_isascii.c ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isdigit.c \
			ft_memdel.c ft_strclr.c ft_strncpy.c
VPATH	= $(SRC_DIR)
INC		= -I./includes
O_DIR	= ./obj
OBJ		= $(addprefix $(O_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\nCreating archive library."
	@ar rc $(NAME) $(OBJ)
	@echo "Updating table of content of archive library."
	@ranlib $(NAME)

$(O_DIR)/%.o: %.c
	@mkdir -p $(O_DIR)
	@printf "."
	@$(CC) $(CFLAGS) -c $< -I ./includes -o $@

clean:
	@echo "Deleting obj files."
	@rm -f $(OBJ)

fclean: clean
	@echo "Deleting archive library."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re