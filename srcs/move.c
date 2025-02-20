/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:39:11 by pchapuis          #+#    #+#             */
/*   Updated: 2023/03/03 11:28:00 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	find_player_position(t_data *img)
{
	int	height;
	int	width;

	height = 0;
	while (height < img->map.height)
	{
		width = 0;
		while (width < img->map.width)
		{
			if (img->map.map[height][width] == 'P')
			{
				img->map.x = width;
				img->map.y = height;
				img->map.direction = 'S';
			}
			width ++;
		}
		height ++;
	}
}

void	move_forward(t_data *img)
{
	if (img->map.map[img->map.y - 1][img->map.x] == 'E')
	{
		if (img->map.nb_item == img->map.tot_item)
			close_win(img, 0, 9);
	}
	else if (img->map.map[img->map.y - 1][img->map.x] != '1')
	{
		if (img->map.map[img->map.y - 1][img->map.x] == 'C')
		{
			img->map.map[img->map.y - 1][img->map.x] = '0';
			img->map.nb_item ++;
		}
		img->map.map[img->map.y][img->map.x] = '0';
		replace(img);
		img->map.y -= 1;
		img->count ++;
		if (place_moves(img) == 1)
			close_win(img, 3, 9);
	}
	else
		place_bloc(img, img->map.x, img->map.y);
	img->map.direction = 'N';
	place_player(img, 0);
}

void	move_back(t_data *img)
{
	if (img->map.map[img->map.y + 1][img->map.x] == 'E')
	{
		if (img->map.nb_item == img->map.tot_item)
			close_win(img, 0, 9);
	}
	else if (img->map.map[img->map.y + 1][img->map.x] != '1')
	{
		if (img->map.map[img->map.y + 1][img->map.x] == 'C')
		{
			img->map.map[img->map.y + 1][img->map.x] = '0';
			img->map.nb_item ++;
		}
		img->map.map[img->map.y][img->map.x] = '0';
		replace(img);
		img->map.y += 1;
		img->count ++;
		if (place_moves(img) == 1)
			close_win(img, 3, 9);
	}
	else
		place_bloc(img, img->map.x, img->map.y);
	img->map.direction = 'S';
	place_player(img, 0);
}

void	move_right(t_data *img)
{
	if (img->map.map[img->map.y][img->map.x + 1] == 'E')
	{
		if (img->map.nb_item == img->map.tot_item)
			close_win(img, 0, 9);
	}
	else if (img->map.map[img->map.y][img->map.x + 1] != '1')
	{
		if (img->map.map[img->map.y][img->map.x + 1] == 'C')
		{
			img->map.map[img->map.y][img->map.x + 1] = '0';
			img->map.nb_item ++;
		}
		img->map.map[img->map.y][img->map.x] = '0';
		replace(img);
		img->map.x += 1;
		img->count ++;
		if (place_moves(img) == 1)
			close_win(img, 3, 9);
	}
	else
		place_bloc(img, img->map.x, img->map.y);
	img->map.direction = 'E';
	place_player(img, 0);
}

void	move_left(t_data *img)
{
	if (img->map.map[img->map.y][img->map.x - 1] == 'E')
	{
		if (img->map.nb_item == img->map.tot_item)
			close_win(img, 0, 9);
	}
	else if (img->map.map[img->map.y][img->map.x - 1] != '1')
	{
		if (img->map.map[img->map.y][img->map.x - 1] == 'C')
		{
			img->map.map[img->map.y][img->map.x - 1] = '0';
			img->map.nb_item ++;
		}
		img->map.map[img->map.y][img->map.x] = '0';
		replace(img);
		img->map.x -= 1;
		img->count ++;
		if (place_moves(img) == 1)
			close_win(img, 3, 9);
	}
	else
		place_bloc(img, img->map.x, img->map.y);
	img->map.direction = 'O';
	place_player(img, 0);
}
