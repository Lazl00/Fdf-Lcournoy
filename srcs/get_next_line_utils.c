/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:28:59 by lcournoy          #+#    #+#             */
/*   Updated: 2025/01/31 18:07:49 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strchr(const char *str, int c)
{
	size_t			i;
	unsigned char	cc;
	unsigned char	*strr;

	i = 0;
	cc = (unsigned char)c;
	strr = (unsigned char *)str;
	while (str[i])
	{
		if (strr[i] == cc)
			return ((char *)str + i);
		i++;
	}
	if (strr[i] == cc)
		return ((char *)str + i);
	return (NULL);
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*zone;

	zone = malloc(elementCount * elementSize);
	if (zone == NULL)
		return (NULL);
	ft_bzero(zone, (elementCount * elementSize));
	return (zone);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_gnl_dup(const char *str)
{
	char	*cpy;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str == NULL)
		return (NULL);
	cpy = malloc(i + 2);
	if (!cpy)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	if (str[i] == '\n')
		cpy[i] = '\n';
	cpy[i + 1] = '\0';
	return (cpy);
}
