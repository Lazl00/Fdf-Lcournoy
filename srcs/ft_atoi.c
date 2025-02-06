/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:34:40 by lcournoy          #+#    #+#             */
/*   Updated: 2025/02/03 18:22:18 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		total;

	i = 0;
	sign = 1;
	total = 0;
	while (is_space(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		total = (total * 10) + (nptr[i] - '0');
		i++;
	}
	return (total * sign);
}
