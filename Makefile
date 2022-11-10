# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkandemi <bkandemi@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 14:51:24 by bkandemi          #+#    #+#              #
#    Updated: 2022/11/10 15:38:13 by bkandemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = ./src/corewar/
SRC_FILES = main.c\
			exit.c\
			parse_args.c\
			set_player_order.c
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

$(NAME): $(OBJ) $(INC) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)
 
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re:	fclean all