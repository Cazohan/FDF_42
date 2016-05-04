# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/28 13:19:17 by lherbelo          #+#    #+#              #
#*   Updated: 2016/05/02 20:13:16 by lherbelo         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = FdF

#Dir

SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./Object

#Files

SRC_NAME = main.c \
		   ft_map.c \
		   ft_key_hook.c \
		   ft_iso.c \
		   ft_init.c \
		   ft_draw.c \
		   ft_color.c \
		   ft_display.c
INC_NAME = -I ./inc/
LIBS = -L./libft/ -lft

#Util

OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
#INC = $(addprefix $(INC_DIR)/, $(INC_NAME))

#DIV

CC = clang
F_MLX = -L./MinilibX/ -lmlx -framework OpenGL -framework AppKit
F_42 = -Werror -Wall -Wextra

#Rules

all: $(NAME)

$(NAME): makeo makec

makeo:
	make -C ./libft/
	make -C ./MinilibX/
	mkdir -p $(OBJ_DIR)
	$(CC) $(F_42) $(INC) -c $(SRC)
	mv $(SRC_NAME:.c=.o) $(OBJ_DIR)

makec:
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(INC_NAME) $(F_MLX) $(F_42)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft/
	make clean -C ./MinilibX/

re: fclean all

.PHONY: all, clean, fclean, re

