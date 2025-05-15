/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:18:03 by flren             #+#    #+#             */
/*   Updated: 2025/05/15 17:58:24 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	ft_push_map(t_game *game, char *file)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(file);
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (file[i + 1] == 'b' && file[i + 2] == 'e' && file[i + 3] == 'r')
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
	ft_init_game(game); //initialiser les valeurs dans game
	ft_get_map_rows(game, file); //initialiser le nombre de ligne de la map dans game->rows
	ft_get_map(game, file); //stock ligne par ligne dans game->map
	ft_check_map(game); //check si la map est valide
	return (*game);
}
