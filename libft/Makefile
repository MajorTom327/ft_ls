# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/10 21:34:05 by vthomas           #+#    #+#              #
#    Updated: 2016/10/16 11:50:12 by vthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
SRC_PATH = ./
SRC_NAME= ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memswitch.c\
	ft_strlen.c\
	ft_strdup.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_strclr.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strsub.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strsplit.c\
	ft_itoa.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putendl.c\
	ft_putnbr.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_pow.c\
	ft_tpow.c\
	ft_abs.c\
	ft_putnbr_endl.c\
	ft_putnbr_desc.c\
	free_join.c
OBJ_PATH = ./obj/
INC_PATH = ./
INC_NAME = libft.h
INC = $(addprefix -I, $(INC_PATH))
CC = gcc
CFLAGS = -Werror -Wall -Wextra -g
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB_NAME = libft.a
LIB_PATH = ./
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

all: $(NAME)
$(NAME): $(OBJ) $(LIB)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $(INC) -o $@ $<

$(LIB):
	@ar rc $@ $(OBJ)
	@ranlib $@

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -rf $(OBJ_PATH)
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf $(LIB)

re: fclean all

test: re
	@clear
	@$(CC) $(CFLAGS) $(INC) main.c $(LIB)
	@./a.out | cat -e
	@/bin/rm -rf a.out
	@(cd ./ && $(MAKE) fclean)

norme:
	@clear
	@norminette $(SRC) $(INC_PATH)*.h
.PHONY: fclean clean
