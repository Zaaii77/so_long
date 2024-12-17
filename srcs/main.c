/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:31:19 by lowatell          #+#    #+#             */
/*   Updated: 2024/12/02 19:41:52 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	init_struct(&data, &data.sprite, &data.game);
	if (!parsing(ac, av, &data.game))
		return (0);
	hook_master(&data);
	return (0);
}
