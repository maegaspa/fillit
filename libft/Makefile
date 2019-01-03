# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: maegaspa <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/04 18:45:14 by maegaspa     #+#   ##    ##    #+#        #
#    Updated: 2018/12/03 18:23:59 by seanseau    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all fclean clean re

CC = gcc

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

INCLUDE = ../includes/libft.h

FILES = ft_atoi\
ft_bzero\
ft_isalnum\
ft_isalpha\
ft_isascii\
ft_isdigit\
ft_isprint\
ft_isfillit\
ft_itoa\
ft_memalloc\
ft_memccpy\
ft_memchr\
ft_memcmp\
ft_memcpy\
ft_memdel\
ft_memmove\
ft_memset\
ft_putchar\
ft_putchar_fd\
ft_putendl\
ft_putendl_fd\
ft_putnbr\
ft_putnbr_fd\
ft_putstr\
ft_putstr_fd\
ft_strcat\
ft_strchr\
ft_strnchr\
ft_strclr\
ft_strcmp\
ft_strcpy\
ft_strdel\
ft_strdup\
ft_strequ\
ft_striter\
ft_striteri\
ft_strjoin\
ft_strlcat\
ft_strlen\
ft_strmap\
ft_strmapi\
ft_strncat\
ft_strncmp\
ft_strncpy\
ft_strnequ\
ft_strnew\
ft_strnstr\
ft_strrchr\
ft_strrev\
ft_strsplit\
ft_strstr\
ft_strsub\
ft_strtrim\
ft_tolower\
ft_toupper\
ft_lstnew\
ft_lstdelone\
ft_lstdel\
ft_lstadd\
ft_lstiter\
ft_lstmap\
ft_strrev\
ft_swap\
ft_range\
ft_recursive_factorial\
ft_sqrt\
ft_strnlen\
ft_strndup\
ft_isfillit\
get_next_line\
ft_skurt\

SRC = $(addsuffix .c, $(FILES))

OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
		@ar rcs $(NAME) $(OBJ)

%.o:%.c ../includes/libft.h
		@$(CC) $(FLAGS) -o $@ -c $< -I $(INCLUDE)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all
