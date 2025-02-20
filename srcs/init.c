/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:19:07 by pchapuis          #+#    #+#             */
/*   Updated: 2023/03/07 12:39:26 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_map	fill_info_map(void)
{
	t_map	data;

	data.empty = '0';
	data.wall = '1';
	data.item = 'C';
	data.exit = 'E';
	data.player = 'P';
	return (data);
}

void	map_dimension(t_map *data)
{
	int	i;

	data->width = (int)ft_strlen(data->map[0]);
	i = 0;
	while (data->map[i] != NULL)
		i ++;
	data->height = i;
}

int	init_info(t_data *img)
{
	int		width;
	int		height;

	width = img->map.width * 64;
	height = img->map.height * 64;
	img->mlx = mlx_init();
	if (!img->mlx)
		return (ft_free(img->map.map), 1);
	img->mlx_win = mlx_new_window(img->mlx, width, height, "so_long");
	if (!img->mlx_win)
	{
		ft_free(img->map.map);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		return (1);
	}
	img->map.tot_item = count_arg(img->map.map, 'C');
	img->map.nb_item = 0;
	img->count = 0;
	return (0);
}

void	print_map(t_data *img)
{
	background(img);
	place_environnement(img, '1', img->map.img_wall);
	place_environnement(img, 'E', img->map.img_exit);
	place_environnement(img, 'C', img->map.img_item);
	place_player(img, 0);
}
