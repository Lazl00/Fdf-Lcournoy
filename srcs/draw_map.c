/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:22:20 by lcournoy          #+#    #+#             */
/*   Updated: 2025/02/13 16:46:56 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	isometric(int x, int y, int z, t_map map)
{
	t_point	iso;
	int		space;

	space = HAUTEUR / (map.y + map.x);
	iso.x = -((x - y) * cos(ANGLE) * space) + LARGEUR / 2;
	iso.y = ((x + y) * sin(ANGLE) * space - (z * space / 8)) + HAUTEUR / 4;
	return (iso);
}
/*	si on veut le vrai isometrique			(z * space / 10)) */

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
			point_a = isometric(i, j, map->map[i][j], *map);
			if (i != map->y - 1)
			{
				point_b = isometric(i + 1, j, map->map[i + 1][j], *map);
				connect_points(&point_a, &point_b, &vars);
			}
			if (j != map->x - 1)
			{
				point_b = isometric(i, j + 1, map->map[i][j + 1], *map);
				connect_points(&point_a, &point_b, &vars);
			}
		}
		j = -1;
	}
}
