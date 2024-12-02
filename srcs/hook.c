/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:33:12 by lowatell          #+#    #+#             */
/*   Updated: 2024/12/02 19:49:52 by lowatell         ###   ########.fr       */
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

void	draw_game(t_data *data, t_sprite *sprite)
{
	mlx_put_image_to_window(data->mlx, data->wind, sprite->floor, 0, 0);
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
	if (msg)
		return (error_msg(msg));
}

void	load_sprites(t_sprite *sprite, t_data *data)
{
	int	width;
	int	height;

	sprite->wall = mlx_xpm_file_to_image(data->mlx, WALL, &width, &height);
	if (!sprite->wall || (width != height && width != 16))
		return (kill_sprites(sprite, data, "Error\nCan't load sprites"));
	sprite->floor = mlx_xpm_file_to_image(data->mlx, FLOOR,
			&width, &height);
	if (!sprite->floor || (width != height && width != 16))
		return (kill_sprites(sprite, data, "Error\nCan't load sprites"));
	sprite->ext = mlx_xpm_file_to_image(data->mlx, EXT, &width, &height);
	if (!sprite->ext || (width != height && width != 16))
		return (kill_sprites(sprite, data, "Error\nCan't load sprites"));
	sprite->exit = mlx_xpm_file_to_image(data->mlx, EXIT, &width, &height);
	if (!sprite->exit || (width != height && width != 16))
		return (kill_sprites(sprite, data, "Error\nCan't load sprites"));
	sprite->coin = mlx_xpm_file_to_image(data->mlx, COIN, &width, &height);
	if (!sprite->coin || (width != height && width != 16))
		return (kill_sprites(sprite, data, "Error\nCan't load sprites"));
	sprite->player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&width, &height);
	if (!sprite->player || (width != height && width != 16))
		return (kill_sprites(sprite, data, "Error\nCan't load sprites"));
}

void	hook_master(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ;
	data->wind = mlx_new_window(data->mlx, 1000, 800, "so_long");
	if (!data->wind)
		return ;
	load_sprites(&data->sprite, data);
	mlx_loop(data->mlx);
}
