/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:06:40 by lcournoy          #+#    #+#             */
/*   Updated: 2025/02/04 17:54:08 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../MLX42/mlx.h"
# include "../MLX42/mlx_int.h"

# define HAUTEUR 1080
# define LARGEUR 1920

# define CENTRE_X 540
# define CENTRE_Y 960

# define SPACE 25
# define RELIEF 3

# define ANGLE 0.52359877559

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

typedef struct s_map {
	int		x;
	int		y;
	int		**map;
}				t_map;

typedef struct s_line {
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
}				t_line;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_point {
	int		x;
	int		y;
}				t_point;

// draw_map.c
t_point	isometric(int x, int y, int z);
void	draw_map(t_map *map, t_vars vars);

// free_vars.c
int		free_mlx(t_vars *vars);
int		free_map(t_map *map);

// ft_atoi.c
int		is_space(char c);
int		ft_atoi(const char *nptr);

// get_coords.c
t_point	get_coords(int x, int y, t_point *point);

// get_map.c
t_map	*get_map(t_point	size, char	*filename);
int		map_y(char *filename);
int		map_x(char *filename);
void	clear_fd(int fd);
t_point	get_map_size(char *filename);

// get_next_line_utils.c
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_gnl_dup(const char *str);

// get_next_line.c
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*clean_static(char	*current_line);
char	*end_of_file(char *line, char *buffer, char *current_line);
char	*process_static(int fd, char **current_line);

// int_split.c
int		is_digit(char c);
int		**int_split(t_point size, char *filename);
int		*get_line(char *line, int len);

// line.c
void	connect_points(t_point *a, t_point *b, t_vars *vars);
void	draw_line(t_point *a, t_point *b, t_vars *vars);
void	draw_vertical_line(t_point *a, t_point *b, t_vars *vars);
void	draw_horizontal_line(t_point *a, t_point *b, t_vars *vars);
void	init_line(t_line *line, t_point *a, t_point *b);

// main.c
int		close_window(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		main(int argc, char *argv[]);

#endif
