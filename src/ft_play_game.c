/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:38:12 by flren             #+#    #+#             */
/*   Updated: 2025/05/19 14:38:29 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mouse(t_game *game)
{
	ft_close_window(game, CLOSE);
	return (0);
}

int	ft_key(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		ft_close_window(game, CLOSE);
	else if (keycode == XK_w)
		ft_key_up(game);
	else if (keycode == XK_s)
		ft_key_down(game);
	else if (keycode == XK_a)
		ft_key_left(game);
	else if (keycode == XK_d)
		ft_key_right(game);
	ft_printf("Moves : %d\n", game->moves);
	return (0);
}

int	ft_loop_game(t_game *game)
{
	int	r;
	int	c;

	r = game->exit_r;
	c = game->exit_c;
	ft_map_render(game);
	if (game->player_r == r && game->player_c == c)
		ft_close_window(game, CLOSE);
	return (0);
}

void	ft_map_render(t_game *game)
{
	int	r;
	int	c;

	r = 0;
	while (game->map[r])
	{
		c = 0;
		while (game->map[r][c])
		{
			if (game->map[r][c] == '1')
				ft_put_img(game, r * 64, c * 64, game->img_w);
			else if (game->map[r][c] == 'P')
				ft_put_img(game, r * 64, c * 64, game->img_p);
			else if (game->map[r][c] == '0')
				ft_put_img(game, r * 64, c * 64, game->img_f);
			else if (game->map[r][c] == 'E')
				ft_put_img(game, r * 64, c * 64, game->img_e);
			else if (game->map[r][c] == 'C')
				ft_put_img(game, r * 64, c * 64, game->img_c);
			c++;
		}
		r++;
	}
}
