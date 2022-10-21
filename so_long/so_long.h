/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffat <rraffat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 08:31:29 by rraffat           #+#    #+#             */
/*   Updated: 2022/04/30 03:00:19 by rraffat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct s_list{
	char	**s;
	void	*mlx;
	void	*win;
	void	*img;
	void	*wall;
	void	*free;
	void	*eat;
	void	*evil;
	void	*player;
	void	*exit;
	int		t;
	int		w;
	int		i;
	int		y;
	int		p_x;
	int		p_y;
	int		l;
	int		z;
	int		x;
	int		j;
	int		coll;
	int		moves;
	int		width;
	int		height;
	int		wid;
	int		hei;
	int		h;
}		t_list;

int		find_p_y(char **p, int h);
int		find_p_x(char **p, int h);
int		find_c(char **p, char c);
void	exit_map(void);
void	ft_putstr(char *s);
int		get_height(char *file_name, t_list *list, int fd);
int		mov_player(int key, t_list *list);
int		render(t_list *list);
int		exit_map2(t_list *list);
void	player_change(char *c, char *p, t_list *list);
int		cout_coll(t_list *list);
//int	test_maps(char **p, int j, int *i);
//int	test_wall(char **p, int i);
//int	test_wall2(char **p, int j);
//int	test_shap(char **p);
int		test_map(char **m, int h);
#endif