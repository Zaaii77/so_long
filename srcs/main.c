/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowatell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 23:31:19 by lowatell          #+#    #+#             */
/*   Updated: 2024/11/29 18:55:04 by lowatell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	main(int ac, char **av)
{
	void	*mlx_ptr;

	(void)ac;
	(void)av;
	mlx_ptr = mlx_init();
	mlx_new_window(mlx_ptr, 120, 120, "so_long");
	mlx_loop(mlx_ptr);
}
