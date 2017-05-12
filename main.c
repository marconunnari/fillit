/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbuxman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 11:57:56 by qbuxman           #+#    #+#             */
/*   Updated: 2017/05/12 15:50:52 by qbuxman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_check_fd(char *argv)
{
	char	buff[BUFF_SIZE + 1];
	int		open_fd;
	int		read_fd;

	if ((open_fd = open(argv, O_RDONLY)) == -1)
	{
		ft_putstr("open error\n");
		exit(1);
	}
	if ((read_fd = read(open_fd, buff, BUFF_SIZE)) == -1)
	{
		ft_putstr("read error\n");
		exit(1);
	}
	buff[read_fd] = '\0';
	if ((close(open_fd)) == -1)
	{
		ft_putstr("close error\n");
		exit(1);
	}
	ft_check_char(buff);
	ft_check_nb_char(buff);
	ft_check_nb_line(buff);
	ft_check_nb_sharp(buff);
	ft_check_nb_tetri(buff);
}

int				main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("usage : fillit sample.fillit\n");
		return (1);
	}
	if (argc == 2)
	{
		ft_check_fd(argv[1]);
	}
	return (0);
}
