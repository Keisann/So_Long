/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:53:48 by flren             #+#    #+#             */
/*   Updated: 2025/05/14 17:06:04 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "unistd.h"
# include "stdlib.h"
# include "limits.h"
# include "fcntl.h"
# include "stdio.h"

# define SUCCESS 1
# define FAIL 0

typedef struct s_game {

	// Carte
	char	**map;
	int		rows;       // Nombre de lignes de la map Y
	int		cols;       // Nombre de colonnes (= largeur) X

	// Position du joueur
	int		player_c;
	int		player_r;

	// Objectifs
	int		C;      		// Combien a été pris
	int		moves;          // Nombre de déplacements du joueur

	// Counts
	int	count_c;			//Nombre de collectible
	int count_cpy_c;
	int count_e;			//E != 1 Erreur
	int count_cpy_e;
	int count_p;			//P != 1 Erreur

}	t_game;

void	ft_putstr_fd(char *s, int fd);
void	ft_init_game(t_game *game);
void	ft_get_map_rows(t_game *game, char	*file);
t_game	ft_push_map(t_game *game, char *file);
void	ft_error(char **map, char *msg);
void	ft_check_map(t_game *game);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
void	ft_get_map(t_game *game, char *file);
int	ft_map_is_good(t_game *game);
int	ft_is_rectangle(t_game *game);
int	ft_c_is_good(char c);
int	ft_map_closed_1(t_game *game);
void	ft_free_map(char **map);
void	ft_flood_fill(int y, int x, t_game *game, char **map);
void	ft_player(t_game *game);
void	ft_init_count(t_game *game);
void	ft_rm_newline(t_game *game);
int ft_map_finish(t_game *game, char **map);
size_t	ft_strlen(const char *s);


#endif
