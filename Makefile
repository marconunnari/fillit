# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbuxman <qbuxman@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 10:55:37 by qbuxman           #+#    #+#              #
#    Updated: 2017/05/12 18:10:23 by mnunnari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c check.c print.c parse_tetriminos.c check_tetriminos.c

OBJ =

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	gcc $(FLAG) $(SRC) -Ilibft/includes -Llibft -lft

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : clean fclean re all
