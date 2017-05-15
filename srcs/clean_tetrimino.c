/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:02:20 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/15 14:04:18 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void					clean_tetrimino(char *tetr)
{
	int		i;

	i = 0;
	while (i < 16)
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
