#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lherbelo <lherbelo@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2015/12/12 07:57:28 by lherbelo          #+#    #+#             *#
#*   Updated: 2016/02/29 18:09:04 by lherbelo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = libft.a
CC = gcc
FLAG = -Wall -Werror -Wextra
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c\
	  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
	  ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c\
	  ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c\
	  ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c\
	  ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
	  ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c\
	  ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrev.c\
	  ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c\
	  ft_toupper.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
	  ft_lstmap.c ft_lstnew.c ft_intmax.c ft_intmin.c ft_lstprint.c\
	  get_next_line.c

HEAD = -I libft.h

OBJ = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o\
	  ft_isdigit.o ft_isprint.o ft_itoa.o ft_memalloc.o ft_memccpy.o\
	  ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o\
	  ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o\
	  ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o\
	  ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o\
	  ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o\
	  ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o\
	  ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strrev.o\
	  ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o\
	  ft_toupper.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o\
	  ft_lstmap.o ft_lstnew.o ft_intmax.o ft_intmin.o ft_lstprint.o\
	  get_next_line.o

#COLOR CODE
RESET=\033[0m
DARK=\033[132m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m
BOLDBLACK=\033[1m\033[30m
BOLDRED=\033[1m\033[31m
BOLDWHITE=\033[1m\033[37m

all: $(NAME)

$(NAME):
	@echo "$(RED)Achtung! Compilation en cours!!!"
	@$(CC) -c $(FLAG) $(SRC)
	@echo "$(YELLOW)Hop hop hop ! Petite lib :)"
	@ar rc $(NAME) $(OBJ)
	@echo "$(GREEN)Et pouf ! On index tout sa !"
	@ranlib $(NAME)

clean:
	@echo "$(CYAN)Arrrr! Petit cleanachhhh!"
	@rm -f $(OBJ)

fclean:
	@echo "$(MAGENTA)Nettoyache ! $(BOLDRED)BAC +5 femme de ménache,"\
	"$(BOLDWHITE) saleté tenace!!!!"
	@rm -f $(OBJ) $(NAME)

re :
	@echo "$(GREEN)bah ouai quoi!!! On prend tout et on recommence mon ptit!!!"
	@rm -f $(OBJ) $(NAME)
	@$(CC) -c $(FLAG) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

.PHONY: all clean fclean re
