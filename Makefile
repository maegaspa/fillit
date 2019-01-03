# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/21 18:44:37 by seanseau     #+#   ##    ##    #+#        #
#    Updated: 2018/12/17 16:43:08 by seanseau    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit
OBJ = fillit
MAKE = make
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDE = ./includes

FILES = main\
mapchecker\
mapconverter\
mapparser\
mapsolver\
mapcreator\
mapprinter\

SRC = $(addsuffix .c, $(FILES))
OBJ= $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE)
	@echo "Compilation"
	@$(MAKE) -C libft/
	@$(CC) $(FLAGS) -o $(NAME) $(SRC) -I$(INCLUDE) -L libft/ -lft

clean:
	@echo "---------------------------------------"
	@echo "\n-------- Cleaning all .o files --------"
	@echo "\n---------------------------------------"
	@rm -f $(OBJ)
	@$(MAKE) -C libft/ clean

fclean: clean
	@echo "--------------------------------------------"
	@echo "\n- Cleaning 'libft.a' and fillit executable -"
	@echo "\n--------------------------------------------"
	@rm -f $(NAME)
	@rm -f libft/libft.a

re: fclean all
