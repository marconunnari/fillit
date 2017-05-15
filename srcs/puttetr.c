/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttetr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 15:12:58 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/15 14:30:42 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
					int side, int position)
{
	int		**relative_coords;
	int		i;
	int		r;
	int		c;

	i = 0;
	relative_coords = tetr_to_2d(tetrimino);
	square[position / side][position % side] = get_chr(tetrimino);
	while (i < 3)
	{
		r = (position / side) + relative_coords[i][0];
		c = (position % side) + relative_coords[i][1];
		if ((r >= 0 && r < side) && (c >= 0 && c < side)
				&& (square[r][c] == '.'))
			square[r][c] = get_chr(tetrimino);
		else
			return (0);
		i++;
	}
	return (1);
}

void			rem(char *tetrimino, char **square,
					int side, int position)
{
	int		**relative_coords;
	int		i;
	int		r;
	int		c;

	i = 0;
	relative_coords = tetr_to_2d(tetrimino);
	square[position / side][position % side] = '.';
	while (i < 3)
	{
		r = (position / side) + relative_coords[i][0];
		c = (position % side) + relative_coords[i][1];
		if ((r >= 0 && r < side) && (c >= 0 && c < side)
				&& (square[r][c] == get_chr(tetrimino)))
			square[r][c] = '.';
		i++;
	}
}
