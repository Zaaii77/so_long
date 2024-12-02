/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:30:07 by lowatell          #+#    #+#             */
/*   Updated: 2024/12/02 19:40:46 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../libft/incs/libft.h"
# include <fcntl.h>

# ifdef __linux__
#  define AFAIRE 0
# else
#  define UP 13
#  define LEFT 0
#  define RIGHT 2
#  define DOWN 1
#  define ESC 53
# endif

# define CLOSEBTN 17

# define COIN "textures/coin.xpm"
# define WALL "textures/wall.xpm"
# define PLAYER "textures/player.xpm"
# define FLOOR "textures/floor.xpm"
# define EXT "textures/exit.xpm"
# define EXIT "textures/exit_open.xpm"

typedef struct s_game
{
	char	**map;
	int		p;
	int		c;
	int		collected;
	int		e;
	int		x;
	int		y;
	int		move_count;
	int		end;
}	t_game;

typedef struct	s_sprite
{
	void	*wall;
	void	*coin;
	void	*player;
	void	*floor;
	void	*ext;
	void	*exit;
}	t_sprite;

typedef struct	s_data
{
	t_sprite sprite;
	t_game	game;
	void	*mlx;
	void	*wind;
}	t_data;

int		parsing(int ac, char **av, t_game *game);
int		check_map(char **map);
int		map_is_valid(t_game *game);
int		is_valid_file(char *file);
int		move(t_game *game, int key);
int		move_end(t_game *game, int key);
int		is_finishable(t_game *game);
char	**fill_map(char *file);
void	error_msg(char *msg);
void	hook_master(t_data *data);
void	init_struct(t_data *data, t_sprite *sprite, t_game *game);

#endif
