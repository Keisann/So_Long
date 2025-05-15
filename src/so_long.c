/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:34:35 by flren             #+#    #+#             */
/*   Updated: 2025/05/15 15:05:47 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game *game)
{
	int	i = 0;

	while (game->map[i])
	{
		ft_putstr_fd(game->map[i], STDOUT_FILENO);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int	ac, char	**av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Error\nInvalid number of arguments\n", STDERR_FILENO), FAIL);
	game = ft_push_map(&game, av[1]); //parsing + push dans game->map
}

