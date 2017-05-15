/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:40:21 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/15 14:23:03 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				move(char **square, int side, int position, char **tetriminos)
{
	int		row;
	int		column;

	row = position / side;
	column = position % side;
	rem(*tetriminos, square, side, position);
	if (fillit(square, side, position + 1, tetriminos))
		return (1);
	return (0);
}

int				boh(char **square, int side, int position, char **tetriminos)
{
	if (*(tetriminos + 1) == NULL)
		solution(square, side);
	if (fillit(square, side, 0, tetriminos + 1))
		return (1);
	else
	{
		if (move(square, side, position, tetriminos))
			return (1);
	}
	return (0);
}

int				fillit(char **square, int side, int position, char **tetriminos)
{
	if (position >= side * side)
		return (0);
	if (square[position / side][position % side] != '.')
		return (fillit(square, side, position + 1, tetriminos));
	if (put(*tetriminos, square, side, position))
	{
		if (boh(square, side, position, tetriminos))
			return (1);
	}
	else
	{
		if (move(square, side, position, tetriminos))
			return (1);
	}
	return (0);
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
		fillit(square, side, 0, tetriminos);
		side++;
	}
}
