/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:39:08 by pchapuis          #+#    #+#             */
/*   Updated: 2023/03/02 14:18:09 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	fill_path3(t_data *img)
{
	img->map.img_opponent3 = mlx_xpm_file_to_image(img->mlx,
			"./img/slime3.xpm", &img->img_width, &img->img_height);
	if (!img->map.img_opponent3)
		return (12);
	img->map.img_opponent4 = mlx_xpm_file_to_image(img->mlx,
			"./img/slime4.xpm", &img->img_width, &img->img_height);
	if (!img->map.img_opponent4)
		return (13);
	img->map.img_opponent5 = mlx_xpm_file_to_image(img->mlx,
			"./img/slime5.xpm", &img->img_width, &img->img_height);
	if (!img->map.img_opponent5)
		return (14);
	return (0);
}

static int	fill_path2(t_data *img)
{
	img->map.img_player_e = mlx_xpm_file_to_image(img->mlx,
			"./img/player_E.xpm", &img->img_width, &img->img_height);
	if (!img->map.img_player_e)
		return (7);
	img->map.img_item = mlx_xpm_file_to_image(img->mlx, "./img/Rock.xpm",
			&img->img_width, &img->img_height);
	if (!img->map.img_item)
		return (8);
	img->map.img_opponent = mlx_xpm_file_to_image(img->mlx, "./img/slime.xpm",
			&img->img_width, &img->img_height);
	if (!img->map.img_opponent)
		return (9);
	img->map.img_opponent1 = mlx_xpm_file_to_image(img->mlx,
			"./img/slime1.xpm", &img->img_width, &img->img_height);
	if (!img->map.img_opponent1)
		return (10);
	img->map.img_opponent2 = mlx_xpm_file_to_image(img->mlx,
			"./img/slime2.xpm", &img->img_width, &img->img_height);
	if (!img->map.img_opponent2)
		return (11);
	return (fill_path3(img));
}

int	fill_path(t_data *img)
{
	img->map.img_empty = mlx_xpm_file_to_image(img->mlx, "./img/grass.xpm",
			&img->img_width, &img->img_height);
	if (!img->map.img_empty)
		return (1);
	img->map.img_wall = mlx_xpm_file_to_image(img->mlx, "./img/tree.xpm",
			&img->img_width, &img->img_height);
	if (!img->map.img_wall)
		return (2);
	img->map.img_exit = mlx_xpm_file_to_image(img->mlx, "./img/dirt.xpm",
			&img->img_width, &img->img_height);
	if (!img->map.img_exit)
		return (3);
	img->map.img_player_n = mlx_xpm_file_to_image(img->mlx,
			"./img/player_N.xpm", &img->img_width, &img->img_height);
	if (!img->map.img_player_n)
		return (4);
	img->map.img_player_s = mlx_xpm_file_to_image(img->mlx,
			"./img/player_S.xpm", &img->img_width, &img->img_height);
	if (!img->map.img_player_s)
		return (5);
	img->map.img_player_o = mlx_xpm_file_to_image(img->mlx,
			"./img/player_O.xpm", &img->img_width, &img->img_height);
	if (!img->map.img_player_o)
		return (6);
	return (fill_path2(img));
}
