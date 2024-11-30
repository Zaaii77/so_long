/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:30:07 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/30 19:09:47 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../libft/incs/libft.h"
# include <fcntl.h>

# define UP 1
# define LEFT 2
# define RIGHT 3
# define DOWN 4

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
}	t_game;

int		parsing(int ac, char **av, t_game *game);
int		check_map(char **map);
int		map_is_valid(t_game *game);
int		is_valid_file(char *file);
int		move(t_game *game, int key);
int		move_end(t_game *game, int key);
char	**fill_map(char *file);

#endif
