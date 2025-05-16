/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:34:35 by flren             #+#    #+#             */
/*   Updated: 2025/05/16 16:30:31 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i = 0;

	while (map[i])
	{
		ft_putstr_fd(map[i], STDOUT_FILENO);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int	ac, char	**av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Error\nInvalid number of arguments\n", STDERR_FILENO), FAIL);
	ft_push_map(&game, av[1]); //parsing + push dans game->map
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		ft_error(game.map, "Error\nmlx failed to initialize\n");
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.cols * TILE_SIZE, game.rows * TILE_SIZE, "so_long");
	if (!game.win_ptr)
	{
		mlx_destroy_window(game.mlx_ptr, game.win_ptr);
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
		ft_error(game.map, "Error\nFail to open windows\n");
	}
	
}

