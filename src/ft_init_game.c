/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisan <keisan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:19:36 by keisan            #+#    #+#             */
/*   Updated: 2025/04/22 21:22:25 by keisan           ###   ########.fr       */
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
