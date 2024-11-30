/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:45:49 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/30 18:22:48 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	parsing(int ac, char **av, t_game *game)
{
	if (ac < 2 || ac > 3)
		return (0);
	game->map = fill_map(av[1]);
	if (!game->map)
		return (get_next_line(-1), 0);
	if (!check_map(game->map))
		return (ft_printf("map is not valid\n"), 0);
	if (!map_is_valid(game))
		return (ft_printf("map isn't closed\n"), 0);
	return (1);
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
	if (++i == ft_strlen(map[0]))
		return (0);
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
	get_next_line(-1);
	return (i);
}

char	**fill_map(char *file)
{
	char	**map;
	int		i;
	int		fd;
	int		size;

	size = line_count(file);
	if (size < 4)
		return (0);
	map = (char **)malloc((sizeof(char *) * size) + 1);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free_tab(map), NULL);
	i = -1;
	while (++i < size)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (close(fd), free_tab(map), NULL);
	}
	close(fd);
	map[i] = 0;
	return (get_next_line(-1), map);
}
