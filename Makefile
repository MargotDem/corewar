# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 14:51:24 by bkandemi          #+#    #+#              #
#    Updated: 2022/11/08 11:54:43 by bkandemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = ./src/corewar/
SRC_FILES = main.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

INC_DIR = ./includes/
INC_FILES = corewar.h
INC = $(addprefix $(INC_DIR), $(INC_FILES))

LIBFT_DIR = libft/
LIBFT_LIB = libft.a
LIB = $(addprefix $(LIBFT_DIR), $(LIBFT_LIB))

all : $(NAME)

$(NAME): $(OBJ) $(INC)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)
 
fclean: clean
	@make -C $(LIBFT_DIR) clean
	@rm -f $(NAME)

debug:
	@make -C libft/ fclean && make -C libft/
	@$(CC_DEBUG) $(CFLAGS) -c $(C_FILES)
	@$(CC_DEBUG) $(CFLAGS) $(O_FILES) libft/libft.a -o $(NAME)

re:	fclean all