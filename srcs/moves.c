/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:42:51 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/30 19:24:32 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[x][y] == 'P' && game->map[x - 1][y] != '1'
		&& game->map[x - 1][y] != 'E')
	{
		if (game->map[x - 1][y] == 'C')
			game->collected++;
		game->map[x][y] = '0';
		game->map[x][y] = '0';
		game->map[x - 1][y] = 'P';
		game->x--;
		return (1);
	}
	return (0);
}

int	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[x][y] == 'P' && game->map[x][y - 1] != '1'
		&& game->map[x][y - 1] != 'E')
	{
		if (game->map[x][y - 1] == 'C')
			game->collected++;
		game->map[x][y] = '0';
		game->map[x][y - 1] = 'P';
		game->y--;
		return (1);
	}
	return (0);
}

int	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[x][y] == 'P' && game->map[x][y + 1] != '1'
		&& game->map[x][y + 1] != 'E')
	{
		if (game->map[x][y + 1] == 'C')
			game->collected++;
		game->map[x][y] = '0';
		game->map[x][y + 1] = 'P';
		game->y++;
		return (1);
	}
	return (0);
}

int	move_bot(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[x][y] == 'P' && game->map[x + 1][y] != '1'
		&& game->map[x + 1][y] != 'E')
	{
		if (game->map[x + 1][y] == 'C')
			game->collected++;
		game->map[x][y] = '0';
		game->map[x][y] = '0';
		game->map[x + 1][y] = 'P';
		game->x++;
		return (1);
	}
	return (0);
}

int	move(t_game *game, int key)
{
	if (game->c == game->collected)
		return (move_end(game, key));
	if (key == DOWN)
		return (move_bot(game));
	if (key == UP)
		return (move_up(game));
	if (key == LEFT)
		return (move_left(game));
	if (key == RIGHT)
		return (move_right(game));
	else
		return (0);
}
