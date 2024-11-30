/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:31:19 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/30 19:23:59 by lowatell         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_game	game;

	if (!parsing(ac, av, &game))
		return (0);
	print_map(game.map);
	move(&game, UP);
	print_map(game.map);
	while (move(&game, RIGHT) != 2)
		print_map(game.map);
	print_map(game.map);
	free_tab(game.map);
}
