/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:05:36 by pchapuis          #+#    #+#             */
/*   Updated: 2023/03/02 17:39:48 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	place_moves(t_data *img)
{
	ft_putnbr_fd(img->count, 1);
	write(1, " moves\n", 7);
	return (0);
}

void	background(t_data *img)
{
	int		i;
	int		j;

	i = 0;
	while (i < img->map.height)
	{
		j = 0;
		while (j < img->map.width)
		{
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->map.img_empty, j * 64, i * 64);
			j ++;
		}
		i ++;
	}
}

void	place_environnement(t_data *img, char c, void *path)
{
	int		i;
	int		j;

	i = 0;
	while (i < img->map.height)
	{
		j = 0;
		while (j < img->map.width)
		{
			if (img->map.map[i][j] == c)
			{
				place_bloc(img, j, i);
				if (c == 'C')
					mlx_put_image_to_window(img->mlx, img->mlx_win,
						path, j * 64 + 16, i * 64 + 16);
				else
					mlx_put_image_to_window(img->mlx, img->mlx_win,
						path, j * 64, i * 64);
			}
			j ++;
		}
		i ++;
	}
}

void	place_player(t_data *img, int pos)
{
	int	x;
	int	y;

	x = img->map.x * 64;
	y = img->map.y * 64;
	if (pos == 0)
	{
		if (img->map.direction == 'S')
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->map.img_player_s, x, y);
		if (img->map.direction == 'N')
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->map.img_player_n, x, y);
		if (img->map.direction == 'O')
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->map.img_player_o, x, y);
		if (img->map.direction == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->map.img_player_e, x, y);
	}
}

void	place_bloc(t_data *img, int x, int y)
{
	if (img->map.map[y][x] != 'E')
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->map.img_empty, x * 64, y * 64);
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->map.img_exit, x * 64, y * 64);
	if (img->map.map[y][x] == '1' || img->map.map[y][x] == 'C')
	{
		if (img->map.map[y][x] == '1')
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->map.img_wall, x * 64, y * 64);
		if (img->map.map[y][x] == 'C')
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->map.img_item, x * 64 + 16, y * 64 + 16);
	}
}
