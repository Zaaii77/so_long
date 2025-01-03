/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:33:12 by lowatell          #+#    #+#             */
/*   Updated: 2025/01/03 17:03:22 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	init_struct(t_data *data, t_sprite *sprite, t_game *game)
{
	data->mlx = NULL;
	data->wind = NULL;
	sprite->ext = NULL;
	sprite->floor = NULL;
	sprite->player = NULL;
	sprite->coin = NULL;
	sprite->wall = NULL;
	sprite->ext_pl = NULL;
	game->map = NULL;
}

void	kill_sprites(t_sprite *sprite, t_data *data, char *msg)
{
	if (data->mlx && sprite->wall)
		mlx_destroy_image(data->mlx, sprite->wall);
	if (data->mlx && sprite->floor)
		mlx_destroy_image(data->mlx, sprite->floor);
	if (data->mlx && sprite->coin)
		mlx_destroy_image(data->mlx, sprite->coin);
	if (data->mlx && sprite->ext)
		mlx_destroy_image(data->mlx, sprite->ext);
	if (data->mlx && sprite->player)
		mlx_destroy_image(data->mlx, sprite->player);
	if (data->mlx && sprite->ext_pl)
		mlx_destroy_image(data->mlx, sprite->ext_pl);
	free_tab(data->game.map);
	if (data->mlx)
	{
		mlx_clear_window(data->mlx, data->wind);
		mlx_destroy_window(data->mlx, data->wind);
		if (LINUX == 1 && data->mlx)
			mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (msg)
		return (error_msg(msg));
}

void	*sprite_load(void *s, char *file, t_sprite *sprite, t_data *data)
{
	int	width;
	int	height;

	s = mlx_xpm_file_to_image(data->mlx, file, &width, &height);
	if (!s || (width != height && width != XPM))
	{
		kill_sprites(sprite, data, "Error\nCan't load sprites");
		return (NULL);
	}
	return (s);
}

void	load_sprites(t_sprite *sprite, t_data *data)
{
	sprite->wall = sprite_load(sprite->wall, WALL, sprite, data);
	sprite->coin = sprite_load(sprite->coin, COIN, sprite, data);
	sprite->floor = sprite_load(sprite->floor, FLOOR, sprite, data);
	sprite->ext = sprite_load(sprite->ext, EXT, sprite, data);
	sprite->player = sprite_load(sprite->player, PLAYER, sprite, data);
	sprite->ext_pl = sprite_load(sprite->ext_pl, EXTPL, sprite, data);
}

void	hook_master(t_data *data)
{
	int	f_width;
	int	f_height;

	f_width = data->game.width * XPM;
	f_height = data->game.height * XPM;
	if (f_height > MCBHEIGHT || f_width > MCBWIDTH)
		kill_sprites(&data->sprite, data, "Error\nMap too large.");
	data->mlx = mlx_init();
	if (!data->mlx)
		kill_sprites(&data->sprite, data, "Error\nCan't init mlx.");
	data->wind = mlx_new_window(data->mlx, f_width, f_height, "so_long");
	if (!data->wind)
		kill_sprites(&data->sprite, data, "Error\nCan't create window.");
	load_sprites(&data->sprite, data);
	draw_map(data, &data->sprite, &data->game);
	mlx_key_hook(data->wind, &move, data);
	mlx_hook(data->wind, CLOSEBTN, 0, (void *)clean_and_exit, data);
	mlx_loop(data->mlx);
}
