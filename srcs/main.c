/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:07:08 by lcournoy          #+#    #+#             */
/*   Updated: 2025/02/14 17:25:48 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_vars *vars)
{
	if (vars->img.img_ptr)
		mlx_destroy_image(vars->mlx, vars->img.img_ptr);
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

int	check_file(char *filename)
{
	int		file;
	char	buffer;
	int		i;

	i = 0;
	while (filename[i])
		i++;
	while (filename[--i] <= 32)
		;
	if (filename[i] != 'f' || filename[i - 1] != 'd' || filename[i - 2] != 'f' \
			|| filename[i - 3] != '.')
		return (-1);
	file = open(filename, O_RDONLY);
	if (!file)
		return (-1);
	if (read(file, &buffer, 1) == -1)
	{
		close(file);
		return (-1);
	}
	close(file);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_map	*map;

	if (argc != 2 || check_file(argv[1]) == -1)
		return (-1);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (free_mlx(&vars));
	vars.win = mlx_new_window(vars.mlx, LARGEUR, HAUTEUR, "FdF");
	if (!vars.win)
		return (free_mlx(&vars));
	vars.img.img_ptr = mlx_new_image(vars.mlx, LARGEUR, HAUTEUR);
	if (!vars.img.img_ptr)
		return (free_mlx(&vars));
	vars.img.img_pixel_ptr = mlx_get_data_addr(vars.img.img_ptr, \
			&vars.img.bits_per_pixel, &vars.img.line_len, &vars.img.endian);
	map = get_map(get_map_size(argv[1]), argv[1]);
	draw_map(map, vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img_ptr, 0, 0);
	free_map(map);
	mlx_hook(vars.win, 17, 0, close_window, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_loop(vars.mlx);
}
