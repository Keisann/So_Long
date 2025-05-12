/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:51:51 by flren             #+#    #+#             */
/*   Updated: 2025/05/12 18:34:24 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"mlx.h"
#include "so_long.h"

static void	ft_init_count(t_game *game)
{
	int	x;
	int	y;
	
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
				game->count_p += 1;
			else if (game->map[x][y] == 'E')
				game->count_e += 1;
			else if (game->map[x][y] == 'C')
				game->count_c += 1;
			y++;
		}
		x++;
	}
}
int	ft_c_is_good(char c)
{
	if (c != 'C' || c != 'P' || c != 'E' || c != '1' || c != '0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	ft_check_map(t_game *game)
{
	int	i;

	i = 0;
	game->cols = ft_strlen(game->map[0]);
	if ((game->rows < 3 || game->cols < 5) && ft_strlen(game->map[game->rows - 1]) )
		ft_error(game->map, "Error\nMap is too small\n");
	if (game->rows * 35 > 1080 || game->cols * 35 > 1920)
		ft_error(game->map, "Error\nMap is too big\n");
	if (ft_is_rectangle(game) == 1)
		ft_error(game->map, "Error\nMap is not a rectangle\n");
	if (ft_map_is_good(game) == 1)
		ft_error(game->map, "Error\nInvalid symbol in map\n");
	if (ft_map_closed_1(game))
		ft_error(game->map, "Error\nMap not closed by 1\n");
	ft_init_count(game);
	if (game->count_p != 1 || game->count_e != 1 || game->count_c < 1)
		ft_error(game->map, "Error\nMap not valid\n");
}
