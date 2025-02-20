/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doable_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:42:33 by pchapuis          #+#    #+#             */
/*   Updated: 2023/03/03 16:09:12 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_copy(char **cp_map, int i)
{
	while (i > -1)
	{
		free(cp_map[i]);
		i --;
	}
	free(cp_map);
}

static void	doable(char **cp_map, t_map *map, int x, int y)
{
	if (cp_map[x][y] == 'C')
		(map->verif_item)++;
	if (cp_map[x][y] == 'E')
	{
		(map->verif_exit)++;
		return ;
	}
	if (cp_map[x][y] == 'P' || cp_map[x][y] == 'C' || cp_map[x][y] == '0')
		cp_map[x][y] = 'X';
	if ((cp_map[x + 1][y] == 'E' || cp_map[x + 1][y] == 'C'
		|| cp_map[x + 1][y] == '0'))
		doable(cp_map, map, x + 1, y);
	if ((cp_map[x - 1][y] == 'E' || cp_map[x - 1][y] == 'C'
		|| cp_map[x - 1][y] == '0'))
		doable(cp_map, map, x - 1, y);
	if ((cp_map[x][y + 1] == 'E' || cp_map[x][y + 1] == 'C'
		|| cp_map[x][y + 1] == '0'))
		doable(cp_map, map, x, y + 1);
	if ((cp_map[x][y - 1] == 'E' || cp_map[x][y - 1] == 'C'
		|| cp_map[x][y - 1] == '0'))
		doable(cp_map, map, x, y - 1);
}

int	copy(t_data *img)
{
	char	**cp_map;
	int		i;

	cp_map = malloc(sizeof(char *) * (img->map.height + 1));
	if (!cp_map)
		return (1);
	i = 0;
	while (i < img->map.height)
	{
		cp_map[i] = ft_strdup(img->map.map[i]);
		if (!cp_map[i])
			return (free_copy(cp_map, i - 1), 1);
		i ++;
	}
	cp_map[i] = NULL;
	img->map.verif_item = 0;
	img->map.verif_exit = 0;
	doable(cp_map, &img->map, img->map.y, img->map.x);
	ft_free(cp_map);
	if (img->map.verif_exit < 1
		|| img->map.verif_item != count_arg(img->map.map, 'C'))
		return (error_config('F'));
	return (0);
}
