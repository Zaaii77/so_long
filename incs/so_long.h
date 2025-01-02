/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:30:07 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/02 19:38:51 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../libft/incs/libft.h"
# include <fcntl.h>

# ifdef __linux__
#  define UP 119
#  define LEFT 97
#  define DOWN 115
#  define RIGHT 100
#  define ESC 65307
#  define LINUX 1
# else
#  define UP 13
#  define LEFT 0
#  define RIGHT 2
#  define DOWN 1
#  define ESC 53
#  define LINUX 0
# endif

# define MCBHEIGHT 1112
# define MCBWIDTH 1710
# define CLOSEBTN 17

# define COIN "textures/coin.xpm"
# define WALL "textures/wall.xpm"
# define PLAYER "textures/player.xpm"
# define FLOOR "textures/floor.xpm"
# define EXT "textures/ext.xpm"
# define EXTPL "textures/ext_pl.xpm"
# define XPM 64

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		p;
	int		c;
	int		collected;
	int		e;
	int		x;
	int		y;
	int		mc;
}	t_game;

typedef struct s_sprite
{
	void	*wall;
	void	*coin;
	void	*player;
	void	*floor;
	void	*ext;
	void	*ext_pl;
}	t_sprite;

typedef struct s_data
{
	t_sprite	sprite;
	t_game		game;
	void		*mlx;
	void		*wind;
}	t_data;

int		parsing(int ac, char **av, t_game *game);
int		check_map(char **map);
int		map_is_valid(t_game *game);
int		is_valid_file(char *file);
int		move(int key, t_data *data);
int		move_end(int key, t_data *data);
int		is_finishable(t_game *game);
char	**fill_map(char *file, t_game *game);
void	kill_sprites(t_sprite *sprite, t_data *data, char *msg);
void	error_msg(char *msg);
void	win_exit(t_data *data);
void	clean_and_exit(t_data *data);
void	move_player(t_data *data, int x, int y);
void	draw_map(t_data *data, t_sprite *sprite, t_game *game);
void	hook_master(t_data *data);
void	init_struct(t_data *data, t_sprite *sprite, t_game *game);

#endif
