/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:37:33 by lcournoy          #+#    #+#             */
/*   Updated: 2025/02/04 16:37:47 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*get_map(t_point size, char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->x = size.x;
	map->y = size.y;
	map->map = int_split(size, filename);
	return (map);
}

int	map_y(char *filename)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	y = 0;
	line = get_next_line(fd);
	while (line && *line != '\0')
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (close(fd) == -1)
		return (0);
	return (y);
}

int	map_x(char *filename)
{
	int		fd;
	char	*line;
	int		i;
	int		x;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	if (!line || *line == '\0')
	{
		clear_fd(fd);
		return (0);
	}
	i = -1;
	x = 0;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '\n' && (line[i + 1] == ' ' \
					|| line[i + 1] == '\0' || line[i + 1] == '\n'))
			x++;
	}
	free(line);
	clear_fd(fd);
	return (x);
}

void	clear_fd(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

t_point	get_map_size(char *filename)
{
	t_point	map_size;

	map_size.y = map_y(filename);
	map_size.x = map_x(filename);
	return (map_size);
}
