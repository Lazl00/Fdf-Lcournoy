/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:07:37 by lcournoy          #+#    #+#             */
/*   Updated: 2025/02/04 17:44:28 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	**int_split(t_point size, char *filename)
{
	int		fd;
	char	*line;
	int		**tab;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	tab = malloc(sizeof (int *) * size.y);
	line = get_next_line(fd);
	while (line && *line != '\0' && i < size.y)
	{
		tab[i] = get_line(line, size.x);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	if (close(fd) == -1)
		return (0);
	return (tab);
}

int	*get_line(char *line, int len)
{
	int	*tab;
	int	i;
	int	j;

	j = 0;
	i = 0;
	tab = malloc(sizeof(int) * len);
	while (j < len)
	{
		tab[j] = ft_atoi(&line[i]);
		while (is_space(line[i]))
			i++;
		while (line[i] == '-')
			i++;
		while (line[i] == '+')
			i++;
		while (is_digit(line[i]))
			i++;
		j++;
	}
	return (tab);
}
