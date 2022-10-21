/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:16:58 by rraffat           #+#    #+#             */
/*   Updated: 2022/05/01 10:29:04 by rraffat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_p_x(char **p, int h)
{
	int	x;
	int	y;

	x = 0;
	while (x < h)
	{
		y = 0;
		while (p[x][y])
		{
			if (p[x][y] == 'P')
				return (x);
			y++;
		}
		x++;
	}
	return (127);
}

int	find_p_y(char **p, int h)
{
	int	x;
	int	y;

	x = 0;
	while (x < h)
	{
		y = 0;
		while (p[x][y])
		{
			if (p[x][y] == 'P')
				return (y);
			y++;
		}
		x++;
	}
	return (127);
}

int	find_c(char **p, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			if (p[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	cout_coll(t_list *list)
{
	int	c;
	int	i;
	int	j;

	i = 0;
	c = 0;
	while (i < list->h)
	{
		j = 0;
		while (list->s[i][j])
		{
			if (list->s[i][j] == 'C')
				c += 1;
			j++;
		}
		i++;
	}
	return (c);
}
