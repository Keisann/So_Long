/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:18:03 by flren             #+#    #+#             */
/*   Updated: 2025/05/17 06:41:57 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_check_file(char *file)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(file);
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (file[i + 1] == 'b' && file[i + 2] == 'e'
				&& file[i + 3] == 'r' && file[i + 4] == '\0')
				break ;
			else
			{
				ft_putstr_fd("Error\nInvalid file\n", STDERR_FILENO);
				exit(FAIL);
			}
		}
		else if (i == len - 4)
		{
			ft_putstr_fd("Error\nInvalid file\n", STDERR_FILENO);
			exit(FAIL);
		}
		i++;
	}
}

static void	ft_init_game(t_game *game)
{
	game->map = 0;
	game->rows = 0;
	game->cols = 0;
	game->player_c = 0;
	game->player_r = 0;
	game->moves = 0;
	game->count_c = 0;
	game->count_cpy_c = 0;
	game->count_e = 0;
	game->count_cpy_e = 0;
	game->count_p = 0;
}

void	ft_push_map(t_game *game, char *file)
{
	ft_check_file(file);
	ft_init_game(game);
	ft_get_map_rows(game, file);
	ft_get_map(game, file);
	ft_check_map(game);
}
