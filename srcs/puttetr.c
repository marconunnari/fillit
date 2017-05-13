/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttetr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 15:12:58 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/13 19:21:05 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				get_rowlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

int				**tetr_to_coords(char *str)
{
	int		i;
	int		index;
	int		**res;
	int		rowlen;

	i = 0;
	index = 0;
	rowlen = get_rowlen(str);
	res = (int**)malloc(sizeof(int*) * 4);
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '\n')
		{
			res[index] = (int*)malloc(sizeof(int) * 2);
			res[index][0] = i / rowlen;
			res[index][1] = i % rowlen;
			index++;
		}
		i++;
	}
	return (res);
}

int				**tetr_to_2d(char *tetr)
{
	int		i;
	int		**coords;
	int		**res;

	res = (int**)malloc(sizeof(int*) * 3);
	coords = tetr_to_coords(tetr);
	i = 0;
	while (i < 3)
	{
		res[i] = (int*)malloc(sizeof(int) * 2);
		res[i][0] = coords[i + 1][0] - coords[0][0];
		res[i][1] = coords[i + 1][1] - coords[0][1];
		i++;
	}
	return (res);
}

char			get_chr(char *tetr)
{
	while (*tetr)
	{
		if (*tetr != '.')
			return (*tetr);
		tetr++;
	}
	return (0);
}

int				put(char *tetrimino, char **square,
					int side, int row, int col)
{
	int		**relative_coords;
	int		i;
	int		r;
	int		c;

	i = 0;
	relative_coords = tetr_to_2d(tetrimino);
	square[row][col] = get_chr(tetrimino);
	while (i < 3)
	{
		r = row + relative_coords[i][0];
		c = col + relative_coords[i][1];
		if ((r >= 0 && r < side) && (c >= 0 && c < side)
				&& (square[r][c] == '.'))
		{
			square[r][c] = get_chr(tetrimino);
		}
		else
		{
			return 0;
		}
		i++;
	}
	return 1;
}

void				rem(char *tetrimino, char **square,
					int side, int row, int col)
{
	int		**relative_coords;
	int		i;
	int		r;
	int		c;

	i = 0;
	relative_coords = tetr_to_2d(tetrimino);
	square[row][col] = '.';
	while (i < 3)
	{
		r = row + relative_coords[i][0];
		c = col + relative_coords[i][1];
		if ((r >= 0 && r < side) && (c >= 0 && c < side)
				&& (square[r][c] == get_chr(tetrimino)))
			square[r][c] = '.';
		i++;
	}
}
