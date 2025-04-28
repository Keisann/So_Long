/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keisan <keisan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:44:17 by keisan            #+#    #+#             */
/*   Updated: 2025/04/28 16:15:26 by keisan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map_rows(t_game *game, char	*file)
{
	int	fd;
	int	i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error to open file\n", STDERR_FILENO);
		perror(file);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(file);
	game->rows = i;
}

void	ft_get_map(t_game *game, char *file)
{
	int	fd;
	int	i;

	i = 0;
	game->map = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
	{
		ft_putstr_fd("Error Malloc Map\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	
}
