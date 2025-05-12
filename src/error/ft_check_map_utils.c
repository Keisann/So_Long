/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:36:15 by flren             #+#    #+#             */
/*   Updated: 2025/05/12 18:14:19 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mlx.h"
#include "so_long.h"

int	ft_map_is_good(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (ft_c_is_good(game->map[x][y]) == 1)
				return (EXIT_FAILURE);
			y++;
		}
		x++;
	}
	return (EXIT_SUCCESS);
}
int	ft_is_rectangle(t_game *game)
{
	int	i;
	int	cols;

	i = 0;
	while (game->map[i])
	{
		cols = ft_strlen(game->map[i]);
		if (cols != game->cols)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
int	ft_map_closed_1(t_game *game)
{
	int	x;
	int	y;
	
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (x == 0 || x == game->rows - 1)
			{
				if (game->map[x][y] != '1')
					return (EXIT_FAILURE);
				y++;
			}
			else if (y == 0 || y == game->cols - 1)
			{
				if (game->map[x][y] != '1')
					return (EXIT_FAILURE);
				y++;
			}
		}
		x++;
	}
	return (EXIT_SUCCESS);
}
