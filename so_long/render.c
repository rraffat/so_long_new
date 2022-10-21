/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:45:51 by rraffat           #+#    #+#             */
/*   Updated: 2022/10/20 02:26:34 by rraffat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_photo(t_list *list)
{
	if (list->s[list->x][list->j] == '1')
		mlx_put_image_to_window(list->mlx, list->win,
			list->wall, list->l, list->z);
	if (list->s[list->x][list->j] == '0')
		mlx_put_image_to_window(list->mlx, list->win,
			list->free, list->l, list->z);
	if (list->s[list->x][list->j] == 'C')
		mlx_put_image_to_window(list->mlx, list->win,
			list->eat, list->l, list->z);
	if (list->s[list->x][list->j] == 'P')
		mlx_put_image_to_window(list->mlx, list->win,
			list->player, list->l, list->z);
	if (list->s[list->x][list->j] == 'E')
		mlx_put_image_to_window(list->mlx, list->win,
			list->exit, list->l, list->z);
}

int	render(t_list *list)
{
	void	*f;

	list->x = 0;
	list->z = -80;
	f = mlx_xpm_file_to_image(list->mlx, "./xpmfile/free.xpm",
			&list->wid, &list->hei);
	while (list->x < list->h)
	{
		list->j = 0;
		list->z = list->z + 80;
		list->l = 0;
		while (list->s[list->x][list->j])
		{
			if (list->s[list->x][list->j] != '\n')
				mlx_put_image_to_window(list->mlx, list->win,
					f, list->l, list->z);
			print_photo(list);
			list->l = list->l + 80;
			list->j += 1;
		}
		list->x += 1;
	}
	return (0);
}
