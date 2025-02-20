/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchapuis <pchapuis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:32:23 by pchapuis          #+#    #+#             */
/*   Updated: 2023/03/03 16:13:44 by pchapuis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_name(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i ++;
	i --;
	if (file[i] != 'r' || file[i - 1] != 'e' || file[i - 2] != 'b'
		|| file[i - 3] != '.')
		return (0);
	return (1);
}

static int	get_map(int fd, char **tmp, char **tmp1)
{
	char	*tmp2;

	tmp2 = ft_strdup(*tmp);
	if (!tmp2)
		return (free(*tmp), free(*tmp1), 1);
	if (*tmp)
		free(*tmp);
	*tmp = ft_strjoin(tmp2, *tmp1);
	if (!*tmp)
		return (free(tmp2), free(*tmp1), 1);
	free(tmp2);
	free(*tmp1);
	*tmp1 = get_next_line(fd, *tmp);
	return (0);
}

static char	**paste_map(int fd)
{
	char	**map;
	char	*tmp;
	char	*tmp1;

	tmp = ft_strdup("");
	if (!tmp)
		return (NULL);
	tmp1 = get_next_line(fd, tmp);
	while (tmp1 != NULL)
		if (get_map(fd, &tmp, &tmp1) == 1)
			return (NULL);
	free(tmp1);
	if (tmp[0] == '\0')
		return (write(2, "Error\nEmpty map\n", 16), free(tmp), NULL);
	map = ft_split(tmp, '\n');
	return (free(tmp), map);
}

static char	**parsing_map(char **argv)
{
	char	**map;
	int		fd;

	if (check_name(argv[1]) == 0)
		return (error_config('L'), NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror(argv[1]), NULL);
	map = paste_map(fd);
	if (map == NULL)
		return (NULL);
	if (close(fd) == -1)
		return (ft_free(map), NULL);
	return (map);
}

int	config_map(t_data *img, char **argv)
{
	img->map = fill_info_map();
	img->map.map = parsing_map(argv);
	if (img->map.map == NULL)
		return (1);
	if (check_map(img->map) == 1)
		return (ft_free(img->map.map), 1);
	map_dimension(&img->map);
	find_player_position(img);
	return (0);
}
