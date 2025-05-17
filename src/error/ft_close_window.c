/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 05:38:19 by flren             #+#    #+#             */
/*   Updated: 2025/05/17 06:13:37 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_window(t_game *game, int exit_status)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->img_coins != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_coins);
	if (game->img_exit != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
	if (game->img_floor != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_floor);
	if (game->img_player != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_player);
	if (game->img_wall != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_free_map(game->map);
	exit(exit_status);
}
