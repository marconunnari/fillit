/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbuxman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 11:57:56 by qbuxman           #+#    #+#             */
/*   Updated: 2017/05/15 13:58:04 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*ft_check_fd(char *argv)
{
	char	buff[BUFF_SIZE + 1];
	int		open_fd;
	int		read_fd;

	if ((open_fd = open(argv, O_RDONLY)) == -1)
		ft_error("open error\n");
	if ((read_fd = read(open_fd, buff, BUFF_SIZE)) == -1)
		ft_error("read error\n");
	if (read_fd == 0)
		ft_error("empty\n");
	if (buff[read_fd - 2] == '\n' && buff[read_fd - 1] == '\n')
		ft_error("end with double new line\n");
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

void			print_tetriminos(char **tetriminos)
{
	int			i;

	i = 0;
	while (tetriminos[i])
	{
		ft_putendl(tetriminos[i]);
		i++;
	}
}

void			giveletters(char **tetriminos)
{
	int			i;

	i = 0;
	while (tetriminos[i])
	{
		ft_strreplace(tetriminos[i], '#', 'A' + i);
		i++;
	}
}

int				main(int argc, char **argv)
{
	char	*filestr;
	char	**tetriminos;

	if (argc != 2)
		ft_error("usage : fillit sample.fillit\n");
	if (argc == 2)
	{
		filestr = ft_check_fd(argv[1]);
		tetriminos = parse_tetriminos(filestr);
		check_tetriminos(tetriminos);
		giveletters(tetriminos);
		solvefillit(tetriminos);
	}
	return (0);
}
