/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:17:24 by flren             #+#    #+#             */
/*   Updated: 2025/05/05 15:18:35 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_game(t_game *game)
{
	game->map = 0;
	game->rows = 0;
	game->cols = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->total_C = 0;
	game->count_C = 0;
	game->moves = 0;
	game->exits = 0;
}
