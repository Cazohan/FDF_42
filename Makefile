#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/03/15 13:16:41 by lherbelo          #+#    #+#             *#
#*   Updated: 2016/03/16 16:58:46 by lherbelo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = FdF

#Files
LIBS = ./libft/libft.a ./MinilibX/libmlx.a
INC = ./includes/fdf.h ./includes/libft.h
OBJ = $(addprefix ./$(OBJDIR)/, $(SRC:.c=.o))
SRC = *.c

# Directories
SRCDIR = $(addprefix ./sources/, $(SRC))
OBJDIR = Object

#Compilation & Flags
CC = gcc
F42 = -Wall -Werror -Wextra
FMLX = -lmlx -framework OpenGL -framework AppKit

#RULES

all :
	make -C ./libft/
	$(CC) $(SRC) $(INC) $(LIBS) $(F42) $(FMLX)
#	@echo "tu plante?"
#	mkdir -p $(OBJDIR) && mv $(SRC:.c=.o) ./$(OBJDIR)/
#	$(CC) -o $(NAME) $(OBJ) $(INC) $(LIBS) $(F42) $(FMLX)

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -rf $(NAME)

re : fclean
	make all

.PHONY : all re clean fclean


