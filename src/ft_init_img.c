/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 00:36:15 by flren             #+#    #+#             */
/*   Updated: 2025/05/19 14:41:00 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_img(t_game *game, int r, int c, void *img)
{
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, img, c, r);
}

void	ft_init_img(t_game *game)
{
	int	width;
	int	height;

	game->img_p = mlx_xpm_file_to_image(game->mlx_ptr, E_I, &width, &height);
	if (!game->img_p)
		(ft_putstr_fd(EEVEE, 2), ft_close_window(game, CLOSE_ERROR));
	game->img_w = mlx_xpm_file_to_image(game->mlx_ptr, W_I, &width, &height);
	if (!game->img_w)
		(ft_putstr_fd(WALL, 2), ft_close_window(game, CLOSE_ERROR));
	game->img_f = mlx_xpm_file_to_image(game->mlx_ptr, F_I, &width, &height);
	if (!game->img_f)
		(ft_putstr_fd(FLOOR, 2), ft_close_window(game, CLOSE_ERROR));
	game->img_e = mlx_xpm_file_to_image(game->mlx_ptr, P_I, &width, &height);
	if (!game->img_e)
		(ft_putstr_fd(PORTAL, 2), ft_close_window(game, CLOSE_ERROR));
	game->img_c = mlx_xpm_file_to_image(game->mlx_ptr, C_I, &width, &height);
	if (!game->img_c)
		(ft_putstr_fd(COIN, 2), ft_close_window(game, CLOSE_ERROR));
}
