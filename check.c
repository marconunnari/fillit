/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbuxman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:25:12 by qbuxman           #+#    #+#             */
/*   Updated: 2017/05/12 14:28:54 by qbuxman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_char(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n')
		{
			ft_putstr("wrong char");
			exit(1);
		}
		i++;
	}
}

void	ft_check_nb_char(char *buff)
{
	int	i;
	int	nb_char;

	i = 0;
	while (buff[i])
	{
		nb_char = 0;
		while (buff[i] != '\n' && buff[i])
		{
			nb_char++;
			i++;
		}
		if (nb_char != 4 && buff[i - 1] != '\n')
		{
			ft_putstr("error nb char per line");
			exit(1);
		}
		i++;
	}
}

void	ft_check_nb_line(char *buff)
{
	int	i;
	int	nb_line;

	i = 0;
	while (buff[i])
	{
		nb_line = 1;
		while (nb_line <= 4 && buff[i])
		{
			i = i + 5;
			nb_line++;
		}
		if (buff[i] != '\n' && buff[i])
		{
			ft_putstr("wrong number of line");
			exit(1);
		}
		i++;
	}
}

void	ft_check_nb_sharp(char *buff)
{
	int	i;
	int	nb_line;
	int	nb_sharp;

	i = 0;
	while (buff[i])
	{
		nb_line = 0;
		nb_sharp = 0;
		while (nb_line <= 4 && buff[i])
		{
			if (buff[i] == '\n')
				nb_line++;
			if (buff[i] == '#')
				nb_sharp++;
			i++;
		}
		if (nb_sharp != 4)
		{
			ft_putstr("wrong number of sharp");
			exit(1);
		}
	}
}

void	ft_check_nb_tetri(char *buff)
{
	int	i;
	int	tetri;

	i = 0;
	tetri = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
			tetri++;
		i++;
	}
	if (tetri > 104)
	{
		ft_putstr("too much tetriminos");
		exit(1);
	}
}
