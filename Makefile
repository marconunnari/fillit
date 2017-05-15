# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbuxman <qbuxman@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 10:55:37 by qbuxman           #+#    #+#              #
#    Updated: 2017/05/15 13:43:22 by mnunnari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_FILES = main.c check.c print.c parse_tetriminos.c check_tetriminos.c \
	solvefillit.c puttetr.c

SRCS = $(addprefix srcs/, $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

INCLUDES = -Iincludes -Ilibft/includes

FLAG = -Wall -Wextra -Werror

all : $(NAME)

$(OBJS): %.o: %.c
	gcc -Wall -Wextra -Werror $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	@make -C libft
	gcc -o $@ $(FLAG) $(OBJS) $(INCLUDES) -Llibft -lft

clean :
	@make fclean -C libft
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all
