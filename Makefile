# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmbuyamb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 16:59:21 by cmbuyamb          #+#    #+#              #
#    Updated: 2018/09/18 15:57:39 by cmbuyamb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude

NAME = lem-in

SRC_PATH = ./src
LIB_PATH = ./mini_lib
INC_PATH = ./inc
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME =	program.c\
			algo.c\
			link.c\
			move.c\
			solution.c\

LIB_NAME =	free.c\
			list.c\
			n_lengh.c\
			newlist.c\

INC_NAME =	lem-in.h\

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	@make -C libft
	@$(CC) $(FLAGS) -o $@ $^ libft/libft.a
	@echo "      _,  __, _, _    _ _, _"
	@echo "      |   |_  |\/|    | |\ |"
	@echo "      |_  |_  |  | ~~ | | \|"
	@echo "      ~~~ ~~~ ~  ~    ~ ~  ~"
	@echo "\033[1;34mMy_project\t\t\033[1;33mRun_it\t\033[0;32m-Okay-\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ) $(OBJLIB)

fclean: clean
	@rm -rf ./obj $(NAME)
	@cd ./libft && $(MAKE) fclean

re: fclean all

norme:
	@norminette $(SRC) $(LIB) $(INC)
	@cd ./libft && $(MAKE) norme
