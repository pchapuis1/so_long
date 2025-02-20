/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:09:43 by pchapuis          #+#    #+#             */
/*   Updated: 2023/03/07 12:32:29 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_map
{
	char	**map;
	char	empty;
	char	wall;
	char	item;
	char	exit;
	char	player;
	char	opponent;
	int		width;
	int		height;

	void	*img_empty;
	void	*img_wall;
	void	*img_item;
	void	*img_exit;
	void	*img_player_n;
	void	*img_player_s;
	void	*img_player_o;
	void	*img_player_e;
	void	*img_opponent;
	void	*img_opponent1;
	void	*img_opponent2;
	void	*img_opponent3;
	void	*img_opponent4;
	void	*img_opponent5;

	int		x;
	int		y;
	char	direction;
	int		nb_item;
	int		tot_item;
	int		verif_exit;
	int		verif_item;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		img_width;
	int		img_height;
	int		count;
	int		frame;
	t_map	map;
}	t_data;

int		error_config(char c);
void	ft_free(char **map);
void	end(int result);
int		close_win(t_data *img, int result, int nb);
void	destroy_img(t_data *img, int n);

int		config_map(t_data *img, char **argv);
char	*get_next_line(int fd, char *tmp);
int		check_map(t_map data);
int		copy(t_data *img);
void	find_player_position(t_data *img);
int		count_arg(char **map, char c);

t_map	fill_info_map(void);
int		fill_path(t_data *img);
void	map_dimension(t_map *data);
int		init_info(t_data *img);

void	print_map(t_data *img);
int		place_moves(t_data *img);
void	background(t_data *img);
void	place_environnement(t_data *img, char c, void *path);
void	place_player(t_data *img, int pos);
void	place_bloc(t_data *img, int x, int y);
void	replace(t_data *img);

void	move_forward(t_data *img);
void	move_back(t_data *img);
void	move_left(t_data *img);
void	move_right(t_data *img);

#endif