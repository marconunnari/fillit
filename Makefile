# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbuxman <qbuxman@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 10:55:37 by qbuxman           #+#    #+#              #
#    Updated: 2017/05/12 15:53:20 by mnunnari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c check.c print.c

OBJ =

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
		gcc $(FLAG) $(SRC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : clean fclean re all
