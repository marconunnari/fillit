/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbuxman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 11:57:56 by qbuxman           #+#    #+#             */
/*   Updated: 2017/05/12 16:03:44 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_check_fd(char *argv)
{
	char	buff[BUFF_SIZE + 1];
	int		open_fd;
	int		read_fd;

	if ((open_fd = open(argv, O_RDONLY)) == -1)
		ft_error("open error\n");
	if ((read_fd = read(open_fd, buff, BUFF_SIZE)) == -1)
		ft_error("read error\n");
	buff[read_fd] = '\0';
	if ((close(open_fd)) == -1)
		ft_error("close error\n");
	ft_check_char(buff);
	ft_check_nb_char(buff);
	ft_check_nb_line(buff);
	ft_check_nb_sharp(buff);
	ft_check_nb_tetri(buff);
	return (ft_strdup(buff));
}

int				main(int argc, char **argv)
{
	char	*filestr;

	if (argc != 2)
		ft_error("usage : fillit sample.fillit\n");
	if (argc == 2)
	{
		ft_check_fd(argv[1]);
		ft_putstr(filestr);
	}
	return (0);
}
