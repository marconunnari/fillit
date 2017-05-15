/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbuxman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:02:58 by qbuxman           #+#    #+#             */
/*   Updated: 2017/05/15 14:29:51 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 1000

void			ft_error(const char *s);
void			print_square(char **square, int side);
void			ft_check_char(char *buff);
void			ft_check_nb_char(char *buff);
void			ft_check_nb_line(char *buff);
void			ft_check_nb_sharp(char *buff);
void			ft_check_nb_tetri(char *buff);
char			**parse_tetriminos(char *str);
void			check_tetriminos(char **tetriminos);
void			solvefillit(char **tetriminos);
int				put(char *tetrimino, char **square,
					int side, int position);
void			rem(char *tetrimino, char **square,
					int side, int position);
void			clean_tetrimino(char *tetr);
int				fillit(char **square, int side,
		int position, char **tetriminos);
void			solution(char **square, int side);
int				**tetr_to_2d(char *tetr);

#endif
