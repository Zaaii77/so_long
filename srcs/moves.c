/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:42:51 by lowatell          #+#    #+#             */
/*   Updated: 2024/12/03 13:48:51 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

static int	move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->game.x;
	y = data->game.y;
	if (data->game.map[x - 1][y] != '1')
	{
		if (data->game.map[x - 1][y] == 'C')
		{
			data->game.collected++;
			data->game.map[x - 1][y] = '0';
		}
		move_player(data, x - 1, y);
		data->game.x--;
		data->game.mc++;
		ft_printf("Number of mouvements : %d\n", data->game.mc);
		return (1);
	}
	return (0);
}

static int	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->game.x;
	y = data->game.y;
	if (data->game.map[x][y - 1] != '1')
	{
		if (data->game.map[x][y - 1] == 'C')
		{
			data->game.collected++;
			data->game.map[x][y - 1] = '0';
		}
		move_player(data, x, y - 1);
		data->game.y--;
		data->game.mc++;
		ft_printf("Number of mouvements : %d\n", data->game.mc);
		return (1);
	}
	return (0);
}

static int	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->game.x;
	y = data->game.y;
	if (data->game.map[x][y + 1] != '1')
	{
		if (data->game.map[x][y + 1] == 'C')
		{
			data->game.collected++;
			data->game.map[x][y + 1] = '0';
		}
		move_player(data, x, y + 1);
		data->game.y++;
		data->game.mc++;
		ft_printf("Number of mouvements : %d\n", data->game.mc);
		return (1);
	}
	return (0);
}

static int	move_bot(t_data *data)
{
	int	x;
	int	y;

	x = data->game.x;
	y = data->game.y;
	if (data->game.map[x + 1][y] != '1')
	{
		if (data->game.map[x + 1][y] == 'C')
		{
			data->game.collected++;
			data->game.map[x + 1][y] = '0';
		}
		move_player(data, x + 1, y);
		data->game.x++;
		data->game.mc++;
		ft_printf("Number of mouvements : %d\n", data->game.mc);
		return (1);
	}
	return (0);
}

int	move(int key, t_data *data)
{
	if (data->game.c == data->game.collected)
		return (move_end(key, data));
	if (key == DOWN)
		return (move_bot(data));
	if (key == UP)
		return (move_up(data));
	if (key == LEFT)
		return (move_left(data));
	if (key == RIGHT)
		return (move_right(data));
	if (key == ESC)
		return (clean_and_exit(data), 0);
	else
		return (0);
}
