/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:51:51 by flren             #+#    #+#             */
/*   Updated: 2025/05/19 14:40:01 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_is_good(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	while (game->map[r])
	{
		c = 0;
		while (game->map[r][c])
		{
			if (ft_c_is_good(game->map[r][c]) == FAIL)
				return (FAIL);
			c++;
		}
		r++;
	}
	return (SUCCESS);
}

int	ft_map_closed_1(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	while (game->map[r])
	{
		c = 0;
		while (game->map[r][c])
		{
			if (r == 0 || r == game->rows - 1)
			{
				if (game->map[r][c] != '1')
					return (FAIL);
			}
			else if (c == 0 || c == game->cols - 1)
			{
				if (game->map[r][c] != '1')
					return (FAIL);
			}
			c++;
		}
		r++;
	}
	return (SUCCESS);
}

int	ft_map_finish(t_game *game, char **map)
{
	int	valid;

	valid = 0;
	ft_flood_fill(game->player_r, game->player_c, game, map);
	if (game->count_cpy_c == 0 && game->count_cpy_e == 1)
		valid = 1;
	else
		valid = 0;
	return (valid);
}

void	ft_check_2(t_game *game, char **cpy_map)
{
	if (game->rows * 35 > 1080 || game->cols * 35 > 1920)
	{
		ft_free_map(cpy_map);
		ft_error(game->map, "Error\nMap is too big\n");
	}
	if (ft_is_rectangle(game) == FAIL)
	{
		ft_free_map(cpy_map);
		ft_error(game->map, "Error\nMap is not a rectangle\n");
	}
	if (ft_map_is_good(game) == FAIL)
	{
		ft_free_map(cpy_map);
		ft_error(game->map, "Error\nInvalid symbol in map\n");
	}
	if (ft_map_closed_1(game) == FAIL)
	{
		ft_free_map(cpy_map);
		ft_error(game->map, "Error\nMap not closed by 1\n");
	}
}

void	ft_check_map(t_game *game)
{
	char	**cpy_map;
	int		i;

	cpy_map = ft_cpy_map(game);
	i = 0;
	if (game->map[0] == 0)
		ft_error(game->map, "Error\nNo Map\n");
	game->cols = ft_strlen(game->map[0]);
	if ((game->rows < 3 || game->cols < 5)
		&& ft_strlen(game->map[game->rows - 1]))
		ft_error(game->map, "Error\nMap is too small\n");
	ft_check_2(game, cpy_map);
	ft_init_count(game);
	if (game->count_p != 1 || game->count_e != 1 || game->count_c < 1)
		(ft_free_map(cpy_map), ft_error(game->map, "Error\nMap not valid\n"));
	ft_player(game);
	if (ft_map_finish(game, cpy_map) == FAIL)
	{
		ft_free_map(cpy_map);
		ft_error(game->map, "Error\nMap is not finishable\n");
	}
	ft_free_map(cpy_map);
}
