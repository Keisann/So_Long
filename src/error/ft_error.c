/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:08:24 by keisan            #+#    #+#             */
/*   Updated: 2025/05/12 14:05:08 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mlx.h"
#include "so_long.h"

static void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error(char **map, char *msg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_free_map(map);
	exit(EXIT_FAILURE);
}