/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:03:24 by pchapuis          #+#    #+#             */
/*   Updated: 2023/03/02 14:17:49 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error_config(char c)
{
	if (c == 'C')
	{
		write(2, "Error\nThe map should contain only 1 exit and", 44);
		write(2, " 1 start position and at least 1 item\n", 38);
	}
	else if (c == 'R')
		write(2, "Error\nThe map has to be rectangle\n", 34);
	else if (c == 'L')
		write(2, "Error\nUsage: ./so_long [*.ber]\n", 31);
	else if (c == 'W')
		write(2, "Error\nThe map must be framed by wall\n", 37);
	else if (c == 'A')
		write(2, "Error\nThere is an unknown character in the map\n", 47);
	else if (c == 'F')
		write(2, "Error\nThe map is not feasibe\n", 29);
	return (1);
}

void	end(int result)
{
	if (result == 0)
		write(1, "You won!\n", 9);
	else if (result == 1)
		write(1, "You lost!\n", 10);
	else if (result == 2)
		write(1, "You left the game!\n", 19);
	else if (result == 3)
		write(2, "Error malloc\n", 13);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i ++;
	}
	free(map);
}

static void	destroy_img2(t_data *img, int n)
{
	if (n > 9)
		mlx_destroy_image(img->mlx, img->map.img_opponent);
	if (n > 10)
		mlx_destroy_image(img->mlx, img->map.img_opponent1);
	if (n > 11)
		mlx_destroy_image(img->mlx, img->map.img_opponent2);
	if (n > 12)
		mlx_destroy_image(img->mlx, img->map.img_opponent3);
	if (n > 13)
		mlx_destroy_image(img->mlx, img->map.img_opponent4);
	if (n > 14)
		mlx_destroy_image(img->mlx, img->map.img_opponent5);
}

void	destroy_img(t_data *img, int n)
{
	if (n > 1)
		mlx_destroy_image(img->mlx, img->map.img_empty);
	if (n > 2)
		mlx_destroy_image(img->mlx, img->map.img_wall);
	if (n > 3)
		mlx_destroy_image(img->mlx, img->map.img_exit);
	if (n > 4)
		mlx_destroy_image(img->mlx, img->map.img_player_n);
	if (n > 5)
		mlx_destroy_image(img->mlx, img->map.img_player_s);
	if (n > 6)
		mlx_destroy_image(img->mlx, img->map.img_player_o);
	if (n > 7)
		mlx_destroy_image(img->mlx, img->map.img_player_e);
	if (n > 8)
		mlx_destroy_image(img->mlx, img->map.img_item);
	destroy_img2(img, n);
}
