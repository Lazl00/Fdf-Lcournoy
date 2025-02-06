/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:07:08 by lcournoy          #+#    #+#             */
/*   Updated: 2025/02/04 17:54:35 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_vars *vars)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		close_window(vars);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_map	*map;

	(void)argc;
	if (argc != 2)
		return (-1);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (-1);
	vars.win = mlx_new_window(vars.mlx, LARGEUR, HAUTEUR, "FdF");
	if (!vars.win)
		return (free_mlx(&vars));
	map = get_map(get_map_size(argv[1]), argv[1]);
	draw_map(map, vars);
	free_map(map);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_loop(vars.mlx);
}
