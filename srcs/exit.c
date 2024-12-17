/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <lowatell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:19:58 by lowatell          #+#    #+#             */
/*   Updated: 2024/12/03 13:52:54 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	win_exit(t_data *data)
{
	ft_printf("You win\n");
	kill_sprites(&data->sprite, data, 0);
	exit(0);
}

void	clean_and_exit(t_data *data)
{
	ft_printf("You give up.\nNoob.");
	kill_sprites(&data->sprite, data, 0);
	exit(0);
}

void	error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(0);
}
