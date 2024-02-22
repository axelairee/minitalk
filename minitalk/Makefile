# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abolea <abolea@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 13:29:11 by abolea            #+#    #+#              #
#    Updated: 2024/02/21 16:19:33 by abolea           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Werror -Wextra -Wall

NAME_S = server
NAME_C = client

SRC_S = server.c
SRC_C = client.c

OBJ_S = $(SRC_S:.c=.o)
OBJ_C = $(SRC_C:.c=.o)

all: $(NAME_S) $(NAME_C)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME_S): $(OBJ_S)
	make -sC libft
	$(CC) $(FLAGS) $(OBJ_S) -L libft -l ft -o $(NAME_S)



$(NAME_C): $(OBJ_C)
	make -sC libft
	$(CC) $(FLAGS) $(OBJ_C) -L libft -l ft -o $(NAME_C)

clean:
	rm -f $(OBJ_S) $(OBJ_C)

fclean: clean
	rm -f $(NAME_S) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re