/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:15:08 by lcournoy          #+#    #+#             */
/*   Updated: 2025/01/31 18:09:39 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*process_static(int fd, char **current_line)
{
	char	*buffer;
	size_t	readed;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!current_line || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_strchr(*current_line, '\n') == NULL)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < BUFFER_SIZE)
			buffer[readed] = '\0';
		if (readed <= 0)
			break ;
		*current_line = ft_strjoin(*current_line, buffer);
	}
	free(buffer);
	if (readed == 0 && (!*current_line || *current_line[0] == '\0'))
	{
		free(*current_line);
		*current_line = NULL;
		return (NULL);
	}
	return (*current_line);
}

char	*get_next_line(int fd)
{
	static char	*current_line = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(current_line), current_line = NULL, NULL);
	if (!current_line)
	{
		current_line = ft_calloc(1, sizeof(char));
		if (!current_line)
			return (NULL);
	}
	current_line = process_static(fd, &current_line);
	if (!current_line)
		return (NULL);
	line = ft_gnl_dup(current_line);
	current_line = clean_static(current_line);
	return (line);
}

char	*clean_static(char *current_line)
{
	char		*rest;
	size_t		i;
	size_t		j;

	i = 0;
	while (current_line[i] && current_line[i] != '\n')
		i++;
	if (!current_line[i] || !current_line[i + 1])
	{
		free(current_line);
		return (NULL);
	}
	rest = malloc(ft_strlen(current_line + i + 1) + 1);
	if (!rest)
		return (NULL);
	j = 0;
	i++;
	while (current_line[i + j])
	{
		rest[j] = current_line[i + j];
		j++;
	}
	rest[j] = '\0';
	free(current_line);
	return (rest);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
