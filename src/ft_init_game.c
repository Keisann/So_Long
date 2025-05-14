/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:17:24 by flren             #+#    #+#             */
/*   Updated: 2025/05/14 13:47:49 by flren            ###   ########.fr       */
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
	game->moves = 0;
	game->C = 0;
	game->count_c = 0;
	game->count_cpy_c = 0;
	game->count_e = 0;
	game->count_cpy_e = 0;
	game->count_p = 0;
}
