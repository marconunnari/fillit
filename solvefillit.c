/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 18:40:21 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/12 20:46:39 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				**tetr_to_coords(char **str)
{
	int		**res;

	len = get_tetrlength(str)
	res = malloc(4)
	while str[i]
		if (str[i] != '.')
			res[index]  malloc(2)
			res[index][0] = i / len;
			res[index][1] = i % len;
	return (res)
}

int				**tetr_to_2d(char *tetr)
{
	int		**coords;
	int		**res;

	res = malloc(3)
	coords = tetr_to_coords(tetr);
	while i < 4
		res[i] = malloc(2)
		res[i][0] = coords[i + 1][0] - coords[i][0];
		res[i][1] = coords[i + 1][1] - coords[i][1];
	return (res);
}

void			put(char *tetrimino, char **square, int side, int row, int col)
{
	int		**relative_coords;

	relative_coords = tetr_to_2d(tetrimino);
	square[row][col] = chr
	for i < 4
		if (row + relative_coords[i][0] >= 0 && row + relative_coords[i][0] <= side)
			if (col + relative_coords[i][1] >= 0 && row + relative_coords[i][1] <= side)
				square[row + relative_coords[i][0], col + relative_coords[i][1]] = chr;
}

int				fillitHelper(char **square, int side, int po, char **tetriminos)
{
	int		row;
	int		column;

	if (position > side * side)
		return 1;
	row = position / side;
	column = position % side;
	if (square[row][column] != 0)
		return fillitHelper(square, side, position + 1);
	for (tetr in tetriminos)
		if (put(tetr, square, side, row, column))
			if (fillitHelper(square, side, position + 1, tetriminos + 1))
				return 1;
		else
			remove(tetr, square, side, row, column);
	return 0
}

void			fillit(char **square, int side, char **tetriminos)
{
	if fillitHelper(square, side, 0, tetriminos)
		solution!! exit
	return 1
}

void			solvefillit(char **tetriminos)
{
	char		**square;
	int			side;

	side = 2;
	while (1)
	{
		square = (char**)malloc(sizeof(char*) * side);
		fillsquarewithzeros(square, side)
		fillit(square, side, tetriminos)
		side++;
	}
}
