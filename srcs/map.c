/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:29:14 by lowatell          #+#    #+#             */
/*   Updated: 2024/12/23 21:17:45 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	put_xpm(t_data *data, void *s, int x, int y)
{
	int	i;

	i = mlx_put_image_to_window(data->mlx, data->wind, s, x, y);
	if (!i)
		kill_sprites(data->sprite, data, "Error\nCant't put xpm");
}

void	move_player(t_data *data, int y, int x)
{
	mlx_put_image_to_window(data->mlx, data->wind, data->sprite.floor,
		data->game.y * XPM, data->game.x * XPM);
	mlx_put_image_to_window(data->mlx, data->wind, data->sprite.player,
		x * XPM, y * XPM);
	if (data->game.map[data->game.x][data->game.y] == 'E')
	{
		if (data->game.c != data->game.collected)
			mlx_put_image_to_window(data->mlx, data->wind,
				data->sprite.ext_pl, data->game.y * XPM,
				data->game.x * XPM);
		else
			mlx_put_image_to_window(data->mlx, data->wind,
				data->sprite.exit, data->game.y
				* XPM, data->game.x * XPM);
	}
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
			if (game->map[y][x] == 'E')
				put_xpm(data, sprite->ext, x * XPM, y * XPM);
			x++;
		}
		y++;
	}
}
