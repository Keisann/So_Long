/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:51:51 by flren             #+#    #+#             */
/*   Updated: 2025/05/14 17:20:24 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player(t_game *game)
{
	int	c;
	int	r;
	
	r = 0;
	while (game->map[r])
	{
		c = 0;
		while (game->map[r][c])
		{
			if (game->map[r][c] == 'P')
			{
				game->player_r = r;
				game->player_c = c;
			}
			c++;
		}
		r++;
	}
}

void	ft_init_count(t_game *game)
{
	int	c;
	int	r;
	
	r = 0;
	while (game->map[r])
	{
		c = 0;
		while (game->map[r][c])
		{
			if (game->map[r][c] == 'P')
				game->count_p += 1;
			else if (game->map[r][c] == 'E')
				game->count_e += 1;
			else if (game->map[r][c] == 'C')
				game->count_c += 1;
			c++;
		}
		r++;
	}
	game->count_cpy_c = game->count_c;
}
int	ft_c_is_good(char c)
{
	if (c != 'C' || c != 'P' || c != 'E' || c != '1' || c != '0')
		return (FAIL);
	return (SUCCESS);
}
int ft_map_finish(t_game *game, char **map)
{
	int valid;
	
	valid = 0;
	ft_flood_fill(game->player_r, game->player_c, game, map);
	if (game->count_cpy_c == 0 && game->count_cpy_e == 1)
		valid = 1;
	return (valid);
}

void	ft_check_map(t_game *game)
{
	char **cpy_map;
	int	i;

	cpy_map = game->map;
	i = 0;
	game->cols = ft_strlen(game->map[0]);
	if ((game->rows < 3 || game->cols < 5) && ft_strlen(game->map[game->rows - 1]) )
		ft_error(game->map, "Error\nMap is too small\n");
	if (game->rows * 35 > 1080 || game->cols * 35 > 1920)
		ft_error(game->map, "Error\nMap is too big\n");
	if (ft_is_rectangle(game) == FAIL)
		ft_error(game->map, "Error\nMap is not a rectangle\n");
	if (ft_map_is_good(game) == FAIL)
		ft_error(game->map, "Error\nInvalid symbol in map\n");
	if (ft_map_closed_1(game) == FAIL)
		ft_error(game->map, "Error\nMap not closed by 1\n");
	ft_init_count(game);
	if (game->count_p != 1 || game->count_e != 1 || game->count_c < 1)
		ft_error(game->map, "Error\nMap not valid\n");
	ft_player(game);
	if (ft_map_finish(game, cpy_map) == FAIL)
		ft_error(game->map, "Error\nMap is not finishable\n");
}
