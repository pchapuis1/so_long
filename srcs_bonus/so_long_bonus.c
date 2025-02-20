/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:28:29 by pchapuis          #+#    #+#             */
/*   Updated: 2023/03/03 16:04:28 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_win(t_data *img, int result, int nb)
{
	end(result);
	if (img->map.map)
		ft_free(img->map.map);
	destroy_img(img, nb);
	mlx_destroy_window(img->mlx, img->mlx_win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	exit(0);
	return (0);
}

static int	key_pressed(int key, t_data *img)
{
	if (key == 119)
		move_forward(img);
	else if (key == 115)
		move_back(img);
	else if (key == 97)
		move_left(img);
	else if (key == 100)
		move_right(img);
	else if (key == 65307)
		close_win(img, 2, 15);
	return (0);
}

static void	hook(t_data *img)
{
	mlx_hook(img->mlx_win, 2, 1L << 0, key_pressed, img);
	mlx_hook(img->mlx_win, 33, 1L << 0, close_win, img);
}

static int	animation(t_data *img)
{
	int	fr;

	fr = 50000;
	if (img->frame == fr * 0.15)
		place_environnement(img, 'O', img->map.img_opponent);
	else if (img->frame == fr * 0.35)
		place_environnement(img, 'O', img->map.img_opponent1);
	else if (img->frame == fr * 0.50)
		place_environnement(img, 'O', img->map.img_opponent2);
	else if (img->frame == fr * 0.65)
		place_environnement(img, 'O', img->map.img_opponent3);
	else if (img->frame == fr * 0.85)
		place_environnement(img, 'O', img->map.img_opponent4);
	else if (img->frame == fr * 1)
		place_environnement(img, 'O', img->map.img_opponent5);
	else if (img->frame > fr * 1)
		img->frame = -1;
	img->frame ++;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	img;
	int		tmp;

	if (argc != 2)
		return (error_config('L'));
	if (config_map(&img, argv) == 1)
		return (1);
	if (copy(&img) == 1)
		return (ft_free(img.map.map), 1);
	if (init_info(&img) == 1)
		return (1);
	tmp = fill_path(&img);
	if (tmp != 0)
		return (close_win(&img, 4, tmp));
	print_map(&img);
	hook(&img);
	mlx_loop_hook(img.mlx, animation, &img);
	mlx_loop(img.mlx);
	return (0);
}
