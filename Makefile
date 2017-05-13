# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbuxman <qbuxman@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 10:55:37 by qbuxman           #+#    #+#              #
#    Updated: 2017/05/13 19:48:35 by mnunnari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_FILES = main.c check.c print.c parse_tetriminos.c check_tetriminos.c \
	solvefillit.c puttetr.c

SRCS = $(addprefix srcs/, $(SRC_FILES))

INCLUDES = -Iincludes -Ilibft/includes

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	gcc -o $@ $(FLAG) $(SRCS) $(INCLUDES) -Llibft -lft

clean :
	make fclean -C libft

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : clean fclean re all
