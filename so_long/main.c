/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:10:25 by rraffat           #+#    #+#             */
/*   Updated: 2022/10/20 18:46:24 by rraffat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char *map)
{
	int	l;

	l = ft_strlen(map);
	if (l < 5)
		return (0);
	if (map[l - 1] != 'r' || map[l - 2] != 'e'
		|| map[l - 3] != 'b' || map[l - 4] != '.')
		return (0);
	return (1);
}

void	list_def(t_list *list)
{
	list->mlx = mlx_init();
	list->p_x = find_p_x(list->s, list->h);
	list->p_y = find_p_y(list->s, list->h);
	list->moves = 1;
	list->l = 10;
	list->z = 80;
	list->width = ft_strlen(list->s[0]) - 1;
	list->height = list->h;
	list->width *= 80;
	list->height *= 80;
	list->coll = cout_coll(list);
}

void	start_new_win(t_list *list)
{
	list->win = mlx_new_window(list->mlx, list->width,
			list->height, "Ragnarok");
	list->player = mlx_xpm_file_to_image(list->mlx, "./xpmfile/player.xpm",
			&list->wid, &list->hei);
	list->wall = mlx_xpm_file_to_image(list->mlx, "./xpmfile/wall.xpm",
			&list->wid, &list->hei);
	list->free = mlx_xpm_file_to_image(list->mlx, "./xpmfile/free.xpm",
			&list->wid, &list->hei);
	list->exit = mlx_xpm_file_to_image(list->mlx, "./xpmfile/exit.xpm",
			&list->wid, &list->hei);
	list->evil = mlx_xpm_file_to_image(list->mlx, "./xpmfile/evil.xpm",
			&list->wid, &list->hei);
	list->eat = mlx_xpm_file_to_image(list->mlx, "./xpmfile/eat.xpm",
			&list->wid, &list->hei);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_list	list;

	if (argc != 2)
		write (1, "number of arguments is wrong", 28);
	if (check_map(argv[1]) == 0)
	{
		write (1, " Please add map\n", 16);
		exit (127);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write (1, "sorry map file is wrong\n", 24);
		return (0);
	}
	list.h = get_height(argv[1], &list, fd);
	if (test_map(list.s, list.h) == 0)
		return (0);
	list_def(&list);
	start_new_win(&list);
	render(&list);
	mlx_hook(list.win, 2, 0, mov_player, &list);
	mlx_hook(list.win, 17, 0, exit_map2, &list);
	mlx_loop(list.mlx);
}
