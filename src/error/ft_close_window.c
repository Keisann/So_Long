/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 05:38:19 by flren             #+#    #+#             */
/*   Updated: 2025/05/19 14:41:30 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_window(t_game *game, int exit_status)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->img_c != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_c);
	if (game->img_e != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_e);
	if (game->img_f != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_f);
	if (game->img_p != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_p);
	if (game->img_w != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_w);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_free_map(game->map);
	exit(exit_status);
}
