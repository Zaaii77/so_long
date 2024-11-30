/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:31:19 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/30 20:03:18 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n");
}

int	print_key(int key, t_game *game)
{
	int	i;

	i = move(game, key);
	if (i == 1)
		ft_printf("number of mouvements : %d\n", game->move_count);
	if (i == 2)
		exit(0);
	print_map(game->map);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	void	*mlx;
	void	*window;

	if (!parsing(ac, av, &game))
		return (0);
	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 500, "so_long");
	mlx_key_hook(window, print_key, &game);
	mlx_loop(mlx);
	if (!parsing(ac, av, &game))
		return (0);
}
