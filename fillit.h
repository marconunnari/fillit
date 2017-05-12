/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbuxman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:02:58 by qbuxman           #+#    #+#             */
/*   Updated: 2017/05/12 18:09:18 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include <stdio.h>
# define BUFF_SIZE 1000

void			ft_error(const char *s);
void			ft_check_char(char *buff);
void			ft_check_nb_char(char *buff);
void			ft_check_nb_line(char *buff);
void			ft_check_nb_sharp(char *buff);
void			ft_check_nb_tetri(char *buff);
char			**parse_tetriminos(char *str);
void			check_tetriminos(char **tetriminos);

#endif
