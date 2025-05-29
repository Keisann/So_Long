/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:34:35 by flren             #+#    #+#             */
/*   Updated: 2025/05/17 06:40:10 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char	**av)
{
	t_game	game;
	int		c;

	if (ac != 2)
		return (ft_putstr_fd("Error\nInvalid number of arguments\n", 2), FAIL);
	ft_push_map(&game, av[1]);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		ft_error(game.map, "Error\nmlx failed to initialize\n");
	c = game.cols * 64;
	game.win_ptr = mlx_new_window(game.mlx_ptr, c, game.rows * 64, "so_long");
	if (!game.win_ptr)
	{
		mlx_destroy_window(game.mlx_ptr, game.win_ptr);
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
		ft_error(game.map, "Error\nFail to open windows\n");
	}
	ft_init_img(&game);
	mlx_loop_hook(game.mlx_ptr, ft_loop_game, &game);
	mlx_hook(game.win_ptr, 17, 0, ft_mouse, &game);
	mlx_hook(game.win_ptr, 02, (1L << 0), ft_key, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
