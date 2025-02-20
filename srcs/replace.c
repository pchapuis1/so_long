/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:12:20 by pchapuis          #+#    #+#             */
/*   Updated: 2023/03/02 14:18:15 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	replace(t_data *img)
{
	place_bloc(img, img->map.x, img->map.y);
	if (img->map.direction == 'N')
		place_bloc(img, img->map.x, img->map.y + 1);
	if (img->map.direction == 'S')
		place_bloc(img, img->map.x, img->map.y - 1);
	if (img->map.direction == 'O')
		place_bloc(img, img->map.x + 1, img->map.y);
	if (img->map.direction == 'E')
		place_bloc(img, img->map.x - 1, img->map.y);
}
