# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-maul <mde-maul@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 20:43:31 by mde-maul          #+#    #+#              #
#    Updated: 2022/10/26 20:43:32 by mde-maul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := asm

.PHONY: all re clean fclean

#COMPILATION
CC := gcc
CFLAGS := -Wall -Werror -Wextra

#INCLUDE
INCL := -I ./includes/
INCL_LIBFT := -I ./libft/

#LIBS
LIBFT := -L ./libft/ -lft

#FILES
FILES := main.c

#SOURCE FILES
SRC_DIR := ./src/

#OBJECT FILES
OBJ_DIR			=	./obj/
OBJS			=	$(addprefix $(OBJ_DIR), $(FILES:%.c=%.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCL) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm $(NAME)

re: fclean all
