/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:52:12 by lcournoy          #+#    #+#             */
/*   Updated: 2025/02/14 15:21:05 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_image *img, int x, int y, int color)
{
	int	offset;

	if (x >= 0 && x <= 1920 && y >= 0 && y <= 1080)
	{
		offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
		*((unsigned int *)(offset + img->img_pixel_ptr)) = color;
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
		put_pixel(&vars->img, x, y, 0xFFFFFF);
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

void	connect_points(t_point *a, t_point *b, t_vars *vars)
{
	if ((a->x == b->x) && (a->y == b->y))
	{
		put_pixel(&vars->img, a->x, a->y, 0xFFFFFF);
		return ;
	}
	draw_line(a, b, vars);
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
