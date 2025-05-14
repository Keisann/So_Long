/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:36:15 by flren             #+#    #+#             */
/*   Updated: 2025/05/14 17:16:53 by flren            ###   ########.fr       */
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
			if (ft_c_is_good(game->map[r][c]) == 1)
				return (FAIL);
			c++;
		}
		r++;
	}
	return (SUCCESS);
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
			return (FAIL);
		i++;
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
void	ft_flood_fill(int r, int c, t_game *game, char **map)
{
	//printf("X = %d | Y = %d\n", x, y);
	//printf("map = %c\n", map[y][x]);
	if (r < 0 || r >= game->rows || c < 0 || c >= game->cols)
		return ;
	if (map[r][c] == '1' || map[r][c] == 'V')
		return ;
	if (map[r][c] == 'C')
		game->count_cpy_c--;
	if (map[r][c] == 'E')
		game->count_cpy_e++;
	map[r][c] = 'V';

	ft_flood_fill(r + 1, c, game, map);
	ft_flood_fill(r - 1, c, game, map);
	ft_flood_fill(r, c + 1, game, map);
	ft_flood_fill(r, c - 1, game, map);
}

