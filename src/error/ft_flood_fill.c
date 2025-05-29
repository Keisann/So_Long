/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 06:45:17 by flren             #+#    #+#             */
/*   Updated: 2025/05/17 06:45:34 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(int r, int c, t_game *game, char **map)
{
	if (r < 0 || r >= game->rows || c < 0 || c >= game->cols)
		return ;
	if (map[r][c] == '1' || map[r][c] == 'V')
		return ;
	if (map[r][c] == 'C')
		game->count_cpy_c--;
	if (map[r][c] == 'E')
	{
		game->count_cpy_e++;
		map[r][c] = 'V';
		return ;
	}
	map[r][c] = 'V';
	ft_flood_fill(r + 1, c, game, map);
	ft_flood_fill(r - 1, c, game, map);
	ft_flood_fill(r, c + 1, game, map);
	ft_flood_fill(r, c - 1, game, map);
}
