/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:34:35 by flren             #+#    #+#             */
/*   Updated: 2025/05/04 17:34:40 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game *game)
{
	int	i = 0;

	while (game->map[i])
	{
		ft_putstr_fd(game->map[i], 1);  // 1 = STDOUT
		i++;
	}
}

int	main(int	ac, char	**av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Invalid number of arguments\n", STDERR_FILENO), EXIT_FAILURE);
	game = ft_push_map(&game, av[1]); //parsing + push dans game->map
	print_map(&game);
}

