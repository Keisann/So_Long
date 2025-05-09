/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:53:48 by flren             #+#    #+#             */
/*   Updated: 2025/05/05 16:29:10 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "unistd.h"
# include "stdlib.h"
# include "limits.h"
# include "fcntl.h"
# include "stdio.h"

typedef struct s_game {

	// Carte
	char	**map;
	int		rows;       // Nombre de lignes de la map
	int		cols;       // Nombre de colonnes (= largeur)

	// Position du joueur
	int		player_x;
	int		player_y;

	// Objectifs
	int		total_C;   		// Nombre total de C dans la map
	int		count_C;      	// Combien a été pris
	int		exits;          // Nombre de sorties (doit être == 1)
	int		moves;          // Nombre de déplacements du joueur

	}	t_game;

void	ft_putstr_fd(char *s, int fd);
void	ft_init_game(t_game *game);
void	ft_get_map_rows(t_game *game, char	*file);
t_game	ft_push_map(t_game *game, char *file);
void	ft_error(char **map, char *msg);
void	ft_check_map(t_game *game);
int	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
void	ft_get_map(t_game *game, char *file);

#endif
