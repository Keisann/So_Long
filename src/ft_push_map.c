/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:18:03 by flren             #+#    #+#             */
/*   Updated: 2025/05/05 16:29:55 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	ft_push_map(t_game *game, char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
	{
		ft_putstr_fd("Invalid file extension\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_init_game(game); //initialiser les valeurs dans game
	ft_get_map_rows(game, file); //initialiser le nombre de ligne de la map dans game->rows
	ft_get_map(game, file); //stock ligne par ligne dans game->map
	ft_check_map(game); //check si la map est valide
	return (*game);
}
