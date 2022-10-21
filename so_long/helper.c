/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 20:18:12 by rraffat           #+#    #+#             */
/*   Updated: 2022/05/01 12:32:05 by rraffat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	exit_map(void)
{
	ft_putstr("Error\n");
	exit (127);
}

int	get_height(char *file_name, t_list *list, int fd)
{
	char	*temp;
	int		h;
	int		i;

	h = 0;
	i = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		free (temp);
		h++;
	}
	close (fd);
	fd = open(file_name, O_RDONLY);
	list->s = malloc (sizeof(char *) * h);
	while (i < h)
	{
		list->s[i] = get_next_line(fd);
		i++;
	}
	return (h);
}

int	exit_map2(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->h)
	{
		free (list->s[i]);
		i++;
	}
	free (list->s);
	mlx_destroy_image (list->mlx, list->player);
	mlx_destroy_image (list->mlx, list->wall);
	mlx_destroy_image (list->mlx, list->free);
	mlx_destroy_image (list->mlx, list->exit);
	mlx_destroy_image (list->mlx, list->eat);
	mlx_destroy_window(list->mlx, list->win);
	exit (0);
}

void	player_change(char *c, char *p, t_list *list)
{	
	if (*p == 'E' && list->coll == 0)
	{
		mlx_destroy_window(list->mlx, list->win);
		exit (0);
	}
	else
	{
		*c = '0';
		*p = 'P';
	}
}
