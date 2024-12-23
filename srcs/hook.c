/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:33:12 by lowatell          #+#    #+#             */
/*   Updated: 2024/12/23 21:21:59 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	init_struct(t_data *data, t_sprite *sprite, t_game *game)
{
	data->mlx = NULL;
	data->wind = NULL;
	sprite->exit = NULL;
	sprite->ext = NULL;
	sprite->floor = NULL;
	sprite->player = NULL;
	sprite->coin = NULL;
	sprite->wall = NULL;
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
	if (data->mlx && sprite->exit)
		mlx_destroy_image(data->mlx, sprite->exit);
	if (data->mlx && sprite->player)
		mlx_destroy_image(data->mlx, sprite->player);
	if (data->mlx && sprite->ext_pl)
		mlx_destroy_image(data->mlx, sprite->ext_pl);
	free_tab(data->game.map);
	mlx_clear_window(data->mlx, data->wind);
	mlx_destroy_window(data->mlx, data->wind);
	if (LINUX == 1)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (msg)
		return (error_msg(msg));
}

void	load_sprites(t_sprite *sprite, t_data *data)
{
	int	width;
	int	height;

	sprite->wall = mlx_xpm_file_to_image(data->mlx, WALL, &width, &height);
	if (!sprite->wall || (width != height && width != XPM))
		return (kill_sprites(sprite, data, "Error\nCan't load WALL.xpm"));
	sprite->floor = mlx_xpm_file_to_image(data->mlx, FLOOR,
			&width, &height);
	if (!sprite->floor || (width != height && width != XPM))
		return (kill_sprites(sprite, data, "Error\nCan't FLOOR.xpm"));
	sprite->ext = mlx_xpm_file_to_image(data->mlx, EXT, &width, &height);
	if (!sprite->ext || (width != height && width != XPM))
		return (kill_sprites(sprite, data, "Error\nCan't load EXT.xpm"));
	sprite->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &width, &height);
	if (!sprite->exit || (width != height && width != XPM))
		return (kill_sprites(sprite, data, "Error\nCan't load EXIT.xpm"));
	sprite->coin = mlx_xpm_file_to_image(data->mlx, COIN, &width, &height);
	if (!sprite->coin || (width != height && width != XPM))
		return (kill_sprites(sprite, data, "Error\nCan't load COIN.xpm"));
	sprite->player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&width, &height);
	if (!sprite->player || (width != height && width != XPM))
		return (kill_sprites(sprite, data, "Error\nCan't load PLAYER.xpm"));
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
		return ;
	data->wind = mlx_new_window(data->mlx, f_width, f_height, "so_long");
	if (!data->wind)
		return ;
	load_sprites(&data->sprite, data);
	draw_map(data, &data->sprite, &data->game);
	mlx_key_hook(data->wind, &move, data);
	mlx_hook(data->wind, CLOSEBTN, 0, (void *)clean_and_exit, data);
	mlx_loop(data->mlx);
}
