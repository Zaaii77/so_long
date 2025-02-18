/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:11:54 by lowatell          #+#    #+#             */
/*   Updated: 2025/02/18 19:21:52 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

char	**map_duplication(char **map)
{
	char	**nmap;
	char	*line;
	int		i;

	i = 0;
	while (map[i])
		i++;
	nmap = (char **)malloc(sizeof(char *) * (i + 1));
	if (!nmap)
		return (NULL);
	i = 0;
	while (map[i])
	{
		line = ft_strdup(map[i]);
		if (!line)
			return (free_tab(nmap), NULL);
		nmap[i] = line;
		i++;
	}
	nmap[i] = 0;
	return (nmap);
}

void	back_tracking(char **map, int x, int y, t_game *game)
{
	map[x][y] = 'A';
	if (y < game->width)
		if (map[x][y + 1] != '1' && map[x][y + 1] != 'A')
			back_tracking(map, x, y + 1, game);
	if (y > 0)
		if (map[x][y - 1] != '1' && map[x][y - 1] != 'A')
			back_tracking(map, x, y - 1, game);
	if (x < game->height)
		if (map[x + 1][y] != '1' && map[x + 1][y] != 'A')
			back_tracking(map, x + 1, y, game);
	if (x > 0)
		if (map[x - 1][y] != '1' && map[x - 1][y] != 'A')
			back_tracking(map, x - 1, y, game);
}

int	check_nmap(char **nmap)
{
	int	i;
	int	j;

	i = 0;
	while (nmap[i])
	{
		j = 0;
		while (nmap[i][j])
		{
			if (nmap[i][j] == 'C' || nmap[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_finishable(t_game *game)
{
	char	**nmap;

	nmap = map_duplication(game->map);
	if (!nmap)
		return (0);
	back_tracking(nmap, game->x, game->y, game);
	if (!check_nmap(nmap))
		return (free_tab(nmap), 0);
	free_tab(nmap);
	return (1);
}
