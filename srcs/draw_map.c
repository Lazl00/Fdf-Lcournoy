/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:22:20 by lcournoy          #+#    #+#             */
/*   Updated: 2025/02/04 18:18:44 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	isometric(int x, int y, int z)
{
	t_point	iso;

	iso.x = -((x - y) * cos(ANGLE) * SPACE) + CENTRE_Y;
	iso.y = ((x + y) * sin(ANGLE) * SPACE - (z * RELIEF)) + CENTRE_X;
	return (iso);
}

void	draw_map(t_map *map, t_vars vars)
{
	int		i;
	int		j;
	t_point	point_a;
	t_point	point_b;

	i = -1;
	j = -1;
	while (++i < map->y)
	{
		while (++j < map->x)
		{
			point_a = isometric(i, j, map->map[i][j]);
			if (i != map->y - 1)
			{
				point_b = isometric(i + 1, j, map->map[i + 1][j]);
				connect_points(&point_a, &point_b, &vars);
			}
			if (j != map->x - 1)
			{
				point_b = isometric(i, j + 1, map->map[i][j + 1]);
				connect_points(&point_a, &point_b, &vars);
			}
		}
		j = -1;
	}
}
