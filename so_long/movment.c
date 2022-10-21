/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:20:20 by rraffat           #+#    #+#             */
/*   Updated: 2022/05/01 12:28:38 by rraffat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_list *list)
{
	if (list->s[list->p_x - 1][list->p_y] == 'C')
		list->coll -= 1;
	if (list->s[list->p_x - 1][list->p_y] == 'E' && list->coll != 0)
	{
		mlx_clear_window(list->mlx, list->win);
		render(list);
	}
	else
	{
		player_change(&(list->s[list->p_x][list->p_y]),
			&(list->s[list->p_x - 1][list->p_y]), list);
		list->p_x -= 1;
		ft_putstr("the number of moves: ");
		ft_putnbr_fd(list->moves++, 1);
		ft_putstr("\r");
	}
}

void	go_left(t_list *list)
{
	if (list->s[list->p_x][list->p_y - 1] == 'C')
		list->coll -= 1;
	if (list->s[list->p_x][list->p_y - 1] == 'E' && list->coll != 0)
	{
		mlx_clear_window(list->mlx, list->win);
		render(list);
	}
	else
	{
		player_change(&(list->s[list->p_x][list->p_y]),
			&(list->s[list->p_x][list->p_y - 1]), list);
		list->p_y -= 1;
		ft_putstr("the number of moves: ");
		ft_putnbr_fd(list->moves++, 1);
		ft_putstr("\r");
	}
}

void	go_down(t_list *list)
{
	if (list->s[list->p_x + 1][list->p_y] == 'C')
		list->coll -= 1;
	if (list->s[list->p_x + 1][list->p_y] == 'E' && list->coll != 0)
	{
		mlx_clear_window(list->mlx, list->win);
		render(list);
	}
	else
	{
		player_change(&(list->s[list->p_x][list->p_y]),
			&(list->s[list->p_x + 1][list->p_y]), list);
		list->p_x += 1;
		ft_putstr("the number of moves: ");
		ft_putnbr_fd(list->moves++, 1);
		ft_putstr("\r");
	}
}

void	go_right(t_list *list)
{
	if (list->s[list->p_x][list->p_y + 1] == 'C')
		list->coll -= 1;
	if (list->s[list->p_x][list->p_y + 1] == 'E' && list->coll != 0)
	{
		mlx_clear_window(list->mlx, list->win);
		render(list);
	}
	else
	{
		player_change(&(list->s[list->p_x][list->p_y]),
			&(list->s[list->p_x][list->p_y + 1]), list);
		list->p_y += 1;
		ft_putstr("the number of moves: ");
		ft_putnbr_fd(list->moves++, 1);
		ft_putstr("\r");
	}
}

int	mov_player(int key, t_list *list)
{
	if (key == 53)
		exit_map2(list);
	if (key == 13)
		if (list->s[list->p_x - 1][list->p_y] != '1')
			go_up(list);
	if (key == 0)
		if (list->s[list->p_x][list->p_y - 1] != '1')
			go_left(list);
	if (key == 1)
	{
		if (list->s[list->p_x + 1][list->p_y] != '1')
			go_down(list);
	}
	if (key == 2)
		if (list->s[list->p_x][list->p_y + 1] != '1')
			go_right(list);
	mlx_clear_window(list->mlx, list->win);
	render(list);
	return (0);
}
