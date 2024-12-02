/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:42:51 by lowatell          #+#    #+#             */
/*   Updated: 2024/12/02 13:18:27 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static int	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[x - 1][y] != '1')
	{
		if (game->map[x - 1][y] == 'E')
		{
			game->x--;
			game->move_count++;
			return (2);
		}
		game->x--;
		game->move_count++;
		return (1);
	}
	return (0);
}

static int	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[x][y - 1] != '1')
	{
		if (game->map[x][y - 1] == 'E')
		{
			game->y--;
			game->move_count++;
			return (2);
		}
		game->y--;
		game->move_count++;
		return (1);
	}
	return (0);
}

static int	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[x][y + 1] != '1')
	{
		if (game->map[x][y + 1] == 'E')
		{
			game->y++;
			game->move_count++;
			return (2);
		}
		game->y++;
		game->move_count++;
		return (1);
	}
	return (0);
}

static int	move_bot(t_game *game)
{
	int	x;
	int	y;

	x = game->x;
	y = game->y;
	if (game->map[x + 1][y] != '1')
	{
		if (game->map[x + 1][y] == 'E')
		{
			game->x++;
			game->move_count++;
			return (2);
		}
		game->x++;
		game->move_count++;
		return (1);
	}
	return (0);
}

int	move_end(t_game *game, int key)
{
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
