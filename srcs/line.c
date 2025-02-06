/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:52:12 by lcournoy          #+#    #+#             */
/*   Updated: 2025/02/04 13:21:23 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	connect_points(t_point *a, t_point *b, t_vars *vars)
{
	if ((a->x == b->x) && (a->y == b->y))
	{
		mlx_pixel_put(vars->mlx, vars->win, a->x, a->y, 0xffffff);
		return ;
	}
	if (a->y == b->y)
	{
		draw_horizontal_line(a, b, vars);
		return ;
	}
	if (a->x == b->x)
	{
		draw_vertical_line(a, b, vars);
		return ;
	}
	draw_line(a, b, vars);
}

void	draw_horizontal_line(t_point *a, t_point *b, t_vars *vars)
{
	int		y;
	int		x;
	int		target;

	y = a->y;
	if (a->x < b->x)
	{
		x = a->x;
		target = b->x;
	}
	if (a->x > b->x)
	{
		x = b->x;
		target = a->x;
	}
	while (x < target)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0xffffff);
		x++;
	}
}

void	draw_vertical_line(t_point *a, t_point *b, t_vars *vars)
{
	int		y;
	int		x;
	int		target;

	x = a->x;
	if (a->y < b->y)
	{
		y = a->y;
		target = b->y;
	}
	if (a->y > b->y)
	{
		y = b->y;
		target = a->y;
	}
	while (y < target)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0xffffff);
		y++;
	}
}

void	draw_line(t_point *a, t_point *b, t_vars *vars)
{
	t_line	line;
	int		x;
	int		y;
	int		e2;

	x = a->x;
	y = a->y;
	init_line(&line, a, b);
	while (1)
	{
		mlx_pixel_put(vars->mlx, vars->win, x, y, 0xffffff);
		if (x == b->x && y == b->y)
			break ;
		e2 = 2 * line.err;
		if (e2 > -line.dy)
		{
			line.err -= line.dy;
			x += line.sx;
		}
		if (e2 < line.dx)
		{
			line.err += line.dx;
			y += line.sy;
		}
	}
}

void	init_line(t_line *line, t_point *a, t_point *b)
{
	line->dx = abs(b->x - a->x);
	line->dy = abs(b->y - a->y);
	line->sx = -1;
	if (a->x < b->x)
		line->sx = 1;
	line->sy = -1;
	if (a->y < b->y)
		line->sy = 1;
	line->err = line->dx - line->dy;
}
