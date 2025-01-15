/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:45:49 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/15 10:19:20 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	parsing(int ac, char **av, t_game *game)
{
	if (ac < 2)
		return (error_msg("Error\nYou may choose a file."), 0);
	if (ac > 2)
		return (error_msg("Error\nYou can only choose one map."), 0);
	if (!is_valid_file(av[1]))
		return (error_msg("Error\nChoose a valid file."), 0);
	game->map = fill_map(av[1], game);
	if (!game->map)
		return (error_msg("Error\n"), 0);
	if (!check_map(game->map))
		return (free_tab(game->map), error_msg("Error\nMap is not valid."), 0);
	if (!map_is_valid(game))
		return (error_msg("Error\nMap is not playable."), 0);
	return (1);
}

int	is_valid_file(char *file)
{
	int	i;
	int	j;

	i = -1;
	j = ft_strlen(file) - 1;
	if (file[j] == 'r')
		if (file[j - 1] == 'e')
			if (file[j - 2] == 'b')
				if (file[j - 3] == '.')
					if ((j - 4) > i)
						return (1);
	return (0);
}

int	check_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = i + 1;
		while (map[j])
		{
			if (ft_strlen(map[j]) != ft_strlen(map[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	line_count(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

char	**fill_map(char *file, t_game *game)
{
	char	**map;
	int		i;
	int		fd;

	game->height = line_count(file);
	if (game->height < 3)
		return (NULL);
	map = (char **)malloc((sizeof(char *) * (game->height + 1)));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (close(fd), free_tab(map), NULL);
	i = 0;
	while (i < game->height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (close(fd), free_tab(map), NULL);
		i++;
	}
	close(fd);
	game->width = ft_strlen(map[0]) - 1;
	map[i] = NULL;
	return (map);
}
