/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:16:06 by flren             #+#    #+#             */
/*   Updated: 2025/05/17 06:27:33 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map_rows(t_game *game, char	*file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFailed to open file\n", STDERR_FILENO);
		perror(file);
		exit(FAIL);
	}
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->rows = i;
}

void	ft_rm_newline(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
			game->map[i][ft_strlen(game->map[i]) - 1] = '\0';
		i++;
	}
}

void	ft_get_map(t_game *game, char *file)
{
	int	fd;
	int	i;

	i = 0;
	game->map = malloc(sizeof(char *) * (game->rows + 1));
	if (!game->map)
	{
		ft_putstr_fd("Error\nMalloc map failed\n", STDERR_FILENO);
		exit(FAIL);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_error(game->map, "Error\nFailed to open file\n");
		perror(file);
		exit(FAIL);
	}
	while (1)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i++])
			break ;
	}
	ft_rm_newline(game);
	close(fd);
}
