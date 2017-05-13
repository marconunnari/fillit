/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnunnari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:44:33 by mnunnari          #+#    #+#             */
/*   Updated: 2017/05/12 18:35:25 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**create_valids()
{
	static char		**valids;

	if (valids != NULL)
		return (valids);
	valids = (char**)malloc((sizeof(char*)) * 20);
	valids[0] = "##\n.#\n.#\n";
	valids[1] = "##\n#.\n#.\n";
	valids[2] = "..#\n###\n";
	valids[3] = "###\n..#\n";
	valids[4] = "#.\n#.\n##\n";
	valids[5] = ".#\n.#\n##\n";
	valids[6] = "###\n#..\n";
	valids[7] = "#..\n###\n";
	valids[8] = "#\n#\n#\n#\n";
	valids[9] = "####\n";
	valids[10] = ".#.\n###\n";
	valids[11] = ".#\n##\n.#\n";
	valids[12] = "#.\n##\n#.\n";
	valids[13] = "###\n.#.\n";
	valids[14] = "#.\n##\n.#\n";
	valids[15] = ".##\n##.\n";
	valids[16] = ".#\n##\n#.\n";
	valids[17] = "##.\n.##\n";
	valids[18] = "##\n##\n";
	valids[19] = NULL;
	return (valids);
}

static void		check_tetrimino(char *tetr)
{
	int		i;
	char	**valids;

	i = 0;
	valids = create_valids();
	while (valids[i])
	{
		if (ft_strequ(valids[i], tetr))
			return ;
		i++;
	}
	ft_error("not valid");
}

void		check_tetriminos(char **tetriminos)
{
	int			i;

	i = 0;
	while (tetriminos[i])
	{
		check_tetrimino(tetriminos[i]);
		i++;
	}
}
