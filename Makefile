# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: maegaspa <maegaspa@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/21 15:42:26 by seanseau     #+#   ##    ##    #+#        #
#    Updated: 2019/01/22 17:14:24 by maegaspa    ###    #+. /#+    ###.fr      #
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
		mapcreator\
		mapsolver\
		tool\

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
