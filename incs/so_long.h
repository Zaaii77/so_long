/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:30:07 by lowatell          #+#    #+#             */
/*   Updated: 2024/12/01 22:48:22 by lowatell         ###   ########.fr       */
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

# define WALL "../textures/wall.xpm"
# define PLAYER "../textures/player.xpm"
# define FLOOR "../textures/floor.xpm"
# define EXIT "../textures/exit.xpm"
# define EXIT_OPEN "../textures/exit_open.xpm"

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
	void	*object;
	void	*player;
	void	*floor;
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

#endif
