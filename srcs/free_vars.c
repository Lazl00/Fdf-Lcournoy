/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:41:27 by lcournoy          #+#    #+#             */
/*   Updated: 2025/02/03 18:03:36 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_mlx(t_vars *vars)
{
	if (vars->mlx)
		free(vars->mlx);
	return (-1);
}

int	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
	return (0);
}
