/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:31:38 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/27 14:54:36 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			DISPLAY_WIDTH, DISPLAY_HEIGHT, "fvck!");
	game->img.img = mlx_new_image(game->mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
								&game->img.line_length,
								&game->img.endian);
}
