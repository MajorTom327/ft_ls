# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vthomas <vthomas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 21:15:40 by vthomas           #+#    #+#              #
#    Updated: 2016/10/11 12:56:27 by vthomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=ft_ls
#Debugging commande (yes/no)
DEBUG=no
CC=clang
ifeq ($(DEBUG),yes)
	CFLAGS= -Wall -Wextra -D DEBUG -Weverything
else
	CFLAGS=-Wall -Wextra -Werror -Weverything
endif

#* ******************************************* *#
#*                  MAIN VAR                   *#
#* These var, are listing all the files needed *#
#* and the directory where they are            *#
#* ******************************************* *#
SRC_PATH=./src/
INC_PATH=./include/
OBJ_PATH=./obj/
LIB_PATH=./
TEST_PATH=./test/

SRC_NAME=main.c\
		get_arg.c\
		ls_exit.c\
		viewer.c\
		sorting.c\
		file_view.c\
		printname.c
INC_NAME=libft.h\
		ft_ls.h
OBJ_NAME=$(SRC_NAME:.c=.o)
LIB_NAME=libft

SRC=$(addprefix $(SRC_PATH),$(SRC_NAME))
INC=$(addprefix -I, $(INC_PATH))
OBJ=$(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB=$(addprefix $(LIB_PATH),$(LIB_NAME))

# Specific to the lib utilisation (More usefull)
#LIB_FILE=$(addprefix $(LIB),/$(addprefix $(LIB_NAME),.a))
LIB_FILE = ./libft/libft.a

#* *********************************************** *#
#*                    MAIN RULES                   *#
#* There, it's the rules who compilate the program *#
#* *********************************************** *#
all: $(NAME)
$(NAME): lib
ifeq ($(DEBUG),yes)
	@echo "\033[32m[MAIN]\033[0m\033[5;31m\t\t(debug)\033[0m"
else
	@echo "\033[32m[MAIN]\t\t(release)\033[0m"
endif
	@echo $(CFLAGS)
	@$(CC) $(CFLAGS) -o $(NAME) $(INC) $(SRC) $(LIB_FILE)
	@chmod +x $(NAME)

# Compilation of all .c with modulable rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

lib:
	@echo "\033[34m[LIBRAIRIES]\033[0m"
	@$(MAKE) -C libft

# Force dependance to be rebuild at all call of the rule(s)
re: fclean all

clean:
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C libft $@

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C libft $@
	@echo "\nWow ! Student clean it so much !\n"

test: re
	@clear
	@echo "\033[5;31;4m\t\tSTART TEST\033[0m\n"
#	@echo "\033[4m./ft_ls:\033[0m"
#	-@./$(NAME)
#	@echo "\n\n"
#	@echo "\033[4m./ft_ls ./include ./src:\033[0m"
#	-@./$(NAME) ./include ./src
#	@echo "\n\n"
#	@echo "\033[4m./ft_ls -GlaF ./:\033[0m"
#	-@./$(NAME) -GlaF ./
	@echo "\033[4m./ft_ls -G -l -a -R:\033[0m"
	-@./$(NAME) -G -l -a -R

norme:
	@norminette $(SRC) $(addprefix $(INC_PATH),$(INC_NAME))

.PHONY: clean
