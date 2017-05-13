/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:40:21 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/13 19:20:39 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			print_square(char **square, int side)
{
	int			i;

	i = 0;
	while (i < side)
	{
		ft_putendl(square[i]);
		i++;
	}
}

void			solution(char **square, int side)
{
	print_square(square, side);
	exit(0);
}

int				fillitHelper(char **square, int side, int position, char **tetriminos)
{
	int		row;
	int		column;

	if (position >= side * side)
		return 0;
	row = position / side;
	column = position % side;
	if (square[row][column] != '.')
		return fillitHelper(square, side, position + 1, tetriminos);
	if (put(*tetriminos, square, side, row, column))
	{
		if (*(tetriminos + 1) == NULL)
			solution(square, side);
		if (fillitHelper(square, side, 0, tetriminos + 1))
			return 1;
		else
		{
			rem(*tetriminos, square, side, row, column);
			if (fillitHelper(square, side, position + 1, tetriminos))
				return 1;
		}
	}
	else
	{
		rem(*tetriminos, square, side, row, column);
		if (fillitHelper(square, side, position + 1, tetriminos))
			return 1;
	}
	return 0;
}

char			**create_square(int side)
{
	char		**square;
	int			i;

	i = 0;
	square = (char**)malloc(sizeof(char*) * side);
	while (i < side)
	{
		square[i] = ft_strnew(side);
		ft_memset(square[i], '.', side);
		i++;
	}
	return (square);
}

void			solvefillit(char **tetriminos)
{
	char		**square;
	int			side;

	side = 2;
	while (1)
	{
		square = create_square(side);
		fillitHelper(square, side, 0, tetriminos);
		side++;
	}
}
