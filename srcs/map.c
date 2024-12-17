/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:29:14 by lowatell          #+#    #+#             */
/*   Updated: 2024/12/17 13:49:13 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	put_xpm(t_data *data, void *s, int x, int y)
{
	int	i;

	i = mlx_put_image_to_window(data->mlx, data->wind, s, x, y);
	if (!i)
		exit(0);
}

void	move_player(t_data *data, int y, int x)
{
	mlx_put_image_to_window(data->mlx, data->wind, data->sprite.floor,
		data->game.y * XPM, data->game.x * XPM);
	mlx_put_image_to_window(data->mlx, data->wind, data->sprite.floor,
		x * XPM, y * XPM);
	mlx_put_image_to_window(data->mlx, data->wind, data->sprite.player,
		x * XPM, y * XPM);
}

void	draw_map(t_data *data, t_sprite *sprite, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_xpm(data, sprite->floor, x * XPM, y * XPM);
			if (game->map[y][x] == 'P')
				put_xpm(data, sprite->player, x * XPM, y * XPM);
			if (game->map[y][x] == '1')
				put_xpm(data, sprite->wall, x * XPM, y * XPM);
			if (game->map[y][x] == 'C')
				put_xpm(data, sprite->coin, x * XPM, y * XPM);
			x++;
		}
		y++;
	}
}
