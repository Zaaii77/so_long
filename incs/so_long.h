/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:30:07 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/30 01:41:19 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../libft/incs/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}	t_map;

typedef struct s_game
{
	char	**map;
	int		collectibles;
	int		x_start;
	int		y_start;
	int		key;
	int		move_count;
}	t_game;

int		parsing(int ac, char **av, t_game *game);
char	**fill_map(char *file);
int		check_map(char **map);

#endif
