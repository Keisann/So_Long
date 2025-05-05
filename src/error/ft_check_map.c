/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:51:51 by flren             #+#    #+#             */
/*   Updated: 2025/05/05 18:24:16 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_game *game)
{
	int	i;

	i = 0;
	game->cols = ft_strlen(game->map[0]);
	if ((game->rows < 3 || game->cols < 5) && ft_strlen(game->map[game->rows - 1]) )
		ft_error(game->map, "Error map too small\n");
	if (game->rows * 35 > 1080 || game->cols * 35 > 1920)
		ft_error(game->map, "Error map too big\n");
}
