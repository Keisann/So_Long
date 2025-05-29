/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 02:09:08 by flren             #+#    #+#             */
/*   Updated: 2025/05/17 06:43:10 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_player(t_game *game, int r, int c)
{
	game->moves++;
	game->map[r][c] = '0';
	if (game->direction == 'w')
		r = r - 1;
	else if (game->direction == 'a')
		c = c - 1;
	else if (game->direction == 'd')
		c = c + 1;
	else if (game->direction == 's')
		r = r + 1;
	if (game->map[r][c] == 'C')
		game->count_c--;
	game->map[r][c] = 'P';
	game->player_c = c;
	game->player_r = r;
}

void	ft_key_up(t_game *game)
{
	int	r;
	int	c;

	r = game->player_r;
	c = game->player_c;
	if (game->map[r - 1][c] == '0' || game->map[r - 1][c] == 'C')
	{
		game->direction = 'w';
		ft_move_player(game, r, c);
	}
	else if (game->map[r - 1][c] == 'E' && game->count_c == 0)
	{
		game->direction = 'w';
		ft_move_player(game, r, c);
	}
}

void	ft_key_down(t_game *game)
{
	int	r;
	int	c;

	r = game->player_r;
	c = game->player_c;
	if (game->map[r + 1][c] == '0' || game->map[r + 1][c] == 'C')
	{
		game->direction = 's';
		ft_move_player(game, r, c);
	}
	else if (game->map[r + 1][c] == 'E' && game->count_c == 0)
	{
		game->direction = 's';
		ft_move_player(game, r, c);
	}
}

void	ft_key_left(t_game *game)
{
	int	r;
	int	c;

	r = game->player_r;
	c = game->player_c;
	if (game->map[r][c - 1] == '0' || game->map[r][c - 1] == 'C')
	{
		game->direction = 'a';
		ft_move_player(game, r, c);
	}
	else if (game->map[r][c - 1] == 'E' && game->count_c == 0)
	{
		game->direction = 'a';
		ft_move_player(game, r, c);
	}
}

void	ft_key_right(t_game *game)
{
	int	r;
	int	c;

	r = game->player_r;
	c = game->player_c;
	if (game->map[r][c + 1] == '0' || game->map[r][c + 1] == 'C')
	{
		game->direction = 'd';
		ft_move_player(game, r, c);
	}
	else if (game->map[r][c + 1] == 'E' && game->count_c == 0)
	{
		game->direction = 'd';
		ft_move_player(game, r, c);
	}
}
