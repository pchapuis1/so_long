/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:06:47 by pchapuis          #+#    #+#             */
/*   Updated: 2023/03/02 17:43:39 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_arg(char **map, char c)
{
	int		nb;
	size_t	width;
	int		length;

	nb = 0;
	length = 0;
	while (map[length] != NULL)
	{
		width = 0;
		while (width < ft_strlen(map[length]))
		{
			if (map[length][width] == c)
				nb ++;
			width ++;
		}
		length ++;
	}
	return (nb);
}

static int	is_rectangle(t_map data)
{
	size_t	width;
	int		i;

	width = ft_strlen(data.map[0]);
	i = 1;
	while (data.map[i] != NULL)
	{
		if (ft_strlen(data.map[i]) != width)
			return (0);
		i ++;
	}
	return (1);
}

static int	check_close_map(char **map, char c)
{
	size_t	i;
	size_t	j;

	j = -1;
	while (++j < ft_strlen(map[0]))
		if (map[0][j] != c)
			return (1);
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != c || map[i][ft_strlen(map[i]) - 1] != c)
			return (1);
		i ++;
	}
	j = -1;
	while (++j < ft_strlen(map[i - 1]))
		if (map[i - 1][j] != c)
			return (1);
	return (0);
}

static int	unknown_arg(t_map data)
{
	size_t	width;
	int		length;

	length = 0;
	while (data.map[length] != NULL)
	{
		width = 0;
		while (width < ft_strlen(data.map[length]))
		{
			if (data.map[length][width] != data.empty
				&& data.map[length][width] != data.exit
				&& data.map[length][width] != data.item
				&& data.map[length][width] != data.player
				&& data.map[length][width] != data.wall)
				return (1);
			width ++;
		}
		length ++;
	}
	return (0);
}

int	check_map(t_map data)
{
	if (is_rectangle(data) == 0)
		return (error_config('R'));
	if (count_arg(data.map, data.exit) != 1
		|| count_arg(data.map, data.player) != 1
		|| count_arg(data.map, data.item) < 1)
		return (error_config('C'));
	if (check_close_map(data.map, data.wall) == 1)
		return (error_config('W'));
	if (unknown_arg(data) == 1)
		return (error_config('A'));
	return (0);
}
