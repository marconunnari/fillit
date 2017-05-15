/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:37:03 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/15 13:40:39 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char			**get_tetriminos(char *str)
{
	char		**res;
	int			i;
	int			size;

	size = (ft_strlen(str) + 1) / 21 ;
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

static int				is_empty(char c)
{
	return (c == '.' || c == 'a');
}

static int				is_linempty(char *tetr, int i)
{
	if (i < 0 || i > 15)
		return (1);
	return (ft_strnequ(&tetr[i], "....", 4) ||
			ft_strnequ(&tetr[i], "aaaa", 4));
}

static int				is_colempty(char *tetr, int i)
{
	if (i < 0 || i > 3)
		return (1);
	return (is_empty(tetr[i]) && is_empty(tetr[i + 5]) &&
			is_empty(tetr[i + 10]) && is_empty(tetr[i + 15]));
}

static void			clean_tetrimino(char *tetr)
{
	int		i;

	i = 0;
	while(i < 16)
	{
		if (is_linempty(tetr, i) &&
				(is_linempty(tetr, i - 5) || is_linempty(tetr, i + 5)))
			ft_memset(&tetr[i], 'a', 5);
		i += 5;
	}

	i = 0;
	while (i < 4)
	{
		if (is_colempty(tetr, i) &&
				(is_colempty(tetr, i - 1) || is_colempty(tetr, i + 1)))
		{
			tetr[i] = 'a';
			tetr[i + 5] = 'a';
			tetr[i + 10] = 'a';
			tetr[i + 15] = 'a';
		}
		i++;
	}

	ft_strremove(tetr, 'a');
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
