/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:48:39 by lowatell          #+#    #+#             */
/*   Updated: 2025/02/18 19:27:28 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	is_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (map[i][++j] != '\n')
		if (map[i][j] != '1')
			return (0);
	while (map[i])
	{
		if ((map[i][0] != '1' && map[i][j - 2] != '1')
			&& map[i][j - 1] != '\n')
			return (0);
		i++;
	}
	j = 0;
	i--;
	while (map[i][j] && map[i][j] != '\n')
	{
		if (map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	is_normed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] != 'E' && map[i][j] != 'C'
				&& map[i][j] != 'P' && map[i][j] != '1'
				&& map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_playable(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'E')
				game->e++;
			else if (game->map[i][j] == 'C')
				game->c++;
			else if (game->map[i][j] == 'P')
			{
				game->p++;
				game->x = i;
				game->y = j;
			}
		}
	}
	if (game->p == 1 && game->e == 1 && game->c > 0)
		return (1);
	return (0);
}

int	map_is_valid(t_game *game)
{
	game->p = 0;
	game->c = 0;
	game->e = 0;
	game->x = 0;
	game->y = 0;
	game->collected = 0;
	game->mc = 0;
	if (!is_closed(game->map))
		return (free_tab(game->map), 0);
	if (!is_playable(game) || !is_normed(game->map))
		return (free_tab(game->map), 0);
	if (!is_finishable(game))
		return (free_tab(game->map), 0);
	return (1);
}
