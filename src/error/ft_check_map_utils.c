/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:36:15 by flren             #+#    #+#             */
/*   Updated: 2025/05/17 05:57:01 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_cpy_map(t_game *game)
{
	int			i;
	char		**cpy_map;

	i = 0;
	cpy_map = malloc(sizeof(char *) * (game->rows + 1));
	if (!cpy_map)
		ft_error(game->map, "Error\nFail malloc cpy_map\n");
	while (game->map[i])
	{
		cpy_map[i] = ft_strdup(game->map[i]);
		if (!cpy_map[i])
			ft_error(game->map, "Error\nFail malloc cpy_map\n");
		i++;
	}
	cpy_map[i] = 0;
	return (cpy_map);
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

int	ft_c_is_good(char c)
{
	if (c == 'C' || c == 'P' || c == 'E' || c == '1' || c == '0')
		return (SUCCESS);
	return (FAIL);
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
			{
				game->count_e += 1;
				game->exit_c = c;
				game->exit_r = r;
			}
			else if (game->map[r][c] == 'C')
				game->count_c += 1;
			c++;
		}
		r++;
	}
	game->count_cpy_c = game->count_c;
}

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
