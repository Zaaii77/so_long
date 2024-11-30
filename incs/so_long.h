/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:30:07 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/30 18:37:29 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../libft/incs/libft.h"
# include <fcntl.h>

typedef struct s_game
{
	char	**map;
	int		p;
	int		c;
	int		e;
	int		x;
	int		y;
	int		move_count;
}	t_game;

int		parsing(int ac, char **av, t_game *game);
int		check_map(char **map);
int		map_is_valid(t_game *game);
int		is_valid_file(char *file);
char	**fill_map(char *file);

#endif
