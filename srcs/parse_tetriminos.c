/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:37:03 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/15 14:04:49 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			**get_tetriminos(char *str)
{
	char		**res;
	int			i;
	int			size;

	size = (ft_strlen(str) + 1) / 21;
	res = (char**)malloc((sizeof(char*)) * size + 1);
	i = 0;
	while (i < size)
	{
		res[i] = ft_strsub(str, 21 * i, 20);
		i++;
	}
	res[i] = NULL;
	return (res);
}

static void			clean_tetriminos(char **tetriminos)
{
	int			i;

	i = 0;
	while (tetriminos[i])
	{
		clean_tetrimino(tetriminos[i]);
		i++;
	}
}

char				**parse_tetriminos(char *str)
{
	char		**res;

	res = get_tetriminos(str);
	clean_tetriminos(res);
	return (res);
}
