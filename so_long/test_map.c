/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 03:07:26 by rraffat           #+#    #+#             */
/*   Updated: 2022/05/01 10:37:10 by rraffat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	test_wall(char **p, int i)
{
	int	k;

	k = 0;
	while (p[0][k] == '1' && p[i - 1][k] == '1')
	{
		k++;
	}
	return (k);
}

int	test_wall2(char **p, int j, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		if (p[i][0] != '1' || p[i][j - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	test_shap(char **p, int h)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (p[i][j])
		{
			if (p[i][j] != '0' && p[i][j] != '1' && p[i][j] != 'C'
					&& p[i][j] != 'E' && p[i][j] != 'P' && p[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	test_num(char **m, int h)
{
	int	c;
	int	i;
	int	j;

	i = 0;
	c = 0;
	while (i < h)
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == 'P')
				c += 1;
			j++;
		}
		i++;
	}
	if (c > 1)
	{
		write (1, "the number of player wrong\n", 27);
		return (0);
	}
	return (1);
}

int	test_map(char **m, int h)
{
	int	j;
	int	w;

	w = 0;
	if (!m)
		return (0);
	j = ft_strlen(m[0]);
	if (test_wall(m, h) != j - 1)
		return (0);
	if (test_wall2(m, j, h) == 0)
		return (0);
	if (test_shap(m, h) == 0)
		return (0);
	w = w + find_c(m, 'C');
	w = w + find_c(m, 'P');
	w = w + find_c(m, 'E');
	if (w != 3)
		return (0);
	if (test_num(m, h) == 0)
		return (0);
	return (1);
}
