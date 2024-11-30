/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:31:19 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/30 01:26:00 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;
	int		i;

	i = 0;
	if (!parsing(ac, av, &game))
		return (0);
	while (game.map[i])
	{
		ft_printf("%s", game.map[i]);
		i++;
	}
	free_tab(game.map);
}
