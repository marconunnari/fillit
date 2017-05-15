/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbuxman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 14:26:17 by qbuxman           #+#    #+#             */
/*   Updated: 2017/05/15 14:18:14 by mnunnari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_error(const char *s)
{
	(void)s;
	ft_putendl("error");
	exit(1);
}

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
