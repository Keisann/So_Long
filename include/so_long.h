/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flren <flren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:53:48 by flren             #+#    #+#             */
/*   Updated: 2025/05/17 06:45:45 by flren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "unistd.h"
# include "stdlib.h"
# include "limits.h"
# include "fcntl.h"
# include "stdio.h"
# include <X11/keysym.h>
# include "mlx.h"

# define SUCCESS 1
# define FAIL 0
# define CLOSE 0
# define CLOSE_ERROR 1

# define EEVEE "Error\nImage Eevee failed to load\n"
# define PORTAL "Error\nImage Portal failed to load\n"
# define FLOOR "Error\nImage Floor failed to load\n"
# define COIN "Error\nImage Coin failed to load\n"
# define WALL "Error\nImage Wall failed to load\n"

# define E_I "img/eevee.xpm"
# define P_I "img/portal.xpm"
# define F_I "img/floor.xpm"
# define C_I "img/coin.xpm"
# define W_I "img/wall.xpm"

typedef struct s_game {
	char	**map;
	int		rows;
	int		cols;
	int		player_c;
	int		player_r;
	int		direction;
	int		exit_c;
	int		exit_r;
	int		moves;
	int		count_c;
	int		count_cpy_c;
	int		count_e;
	int		count_cpy_e;
	int		count_p;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_w;
	void	*img_f;
	void	*img_p;
	void	*img_e;
	void	*img_c;

}	t_game;

void	ft_putstr_fd(char *s, int fd);
void	ft_get_map_rows(t_game *game, char	*file);
void	ft_push_map(t_game *game, char *file);
void	ft_error(char **map, char *msg);
void	ft_check_map(t_game *game);
char	*get_next_line(int fd);
void	ft_get_map(t_game *game, char *file);
int		ft_map_is_good(t_game *game);
int		ft_is_rectangle(t_game *game);
int		ft_c_is_good(char c);
int		ft_map_closed_1(t_game *game);
void	ft_free_map(char **map);
void	ft_flood_fill(int y, int x, t_game *game, char **map);
void	ft_player(t_game *game);
void	ft_init_count(t_game *game);
void	ft_rm_newline(t_game *game);
int		ft_map_finish(t_game *game, char **map);
size_t	ft_strlen(const char *s);
void	ft_close_window(t_game *game, int exit_status);
int		ft_key(int keycode, t_game *game);
int		ft_loop_game(t_game *game);
int		ft_mouse(t_game *game);
void	ft_init_img(t_game *game);
void	ft_map_render(t_game *game);
void	ft_put_img(t_game *game, int r, int c, void *img);
char	*ft_strdup(const char *src);
void	ft_move_player(t_game *game, int r, int c);
void	ft_key_up(t_game *game);
void	ft_key_down(t_game *game);
void	ft_key_left(t_game *game);
void	ft_key_right(t_game *game);
int		ft_key(int keycode, t_game *game);
char	**ft_cpy_map(t_game *game);
void	ft_flood_fill(int r, int c, t_game *game, char **map);

#endif
