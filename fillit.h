/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbuxman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:02:58 by qbuxman           #+#    #+#             */
/*   Updated: 2017/05/09 12:06:17 by qbuxman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 545

void			ft_putstr(const char *s);
static void		ft_check_fd(char *argv);
void			ft_check_char(char *buff);
void			ft_check_nb_char(char *buff);
void			ft_check_nb_line(char *buff);
void			ft_check_nb_sharp(char *buff);
void			ft_check_nb_tetri(char *buff);

#endif
