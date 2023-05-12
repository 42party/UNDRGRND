/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:09:33 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/12 13:21:25 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	move_forward(t_game *game)
{
	if (game->map.map_square[(int)(game->player.pos_y)]
			[(int)(game->player.pos_x + game->player.dir_x
			* game->player.move_speed * 2)] == '0')
		game->player.pos_x += game->player.dir_x * game->player.move_speed;
	if (game->map.map_square[(int)(game->player.pos_y + game->player.dir_y
			* game->player.move_speed * 2)][(int)(game->player.pos_x)] == '0')
		game->player.pos_y += game->player.dir_y * game->player.move_speed;
	raycasting(game);
}

void	move_backward(t_game *game)
{
	if (game->map.map_square[(int)(game->player.pos_y)]
			[(int)(game->player.pos_x - game->player.dir_x
			* game->player.move_speed * 2)] == '0')
		game->player.pos_x -= game->player.dir_x * game->player.move_speed;
	if (game->map.map_square[(int)(game->player.pos_y - game->player.dir_y
			* game->player.move_speed * 2)][(int)(game->player.pos_x)] == '0')
		game->player.pos_y -= game->player.dir_y * game->player.move_speed;
	raycasting(game);
}

void	move_left(t_game *game)
{
	if (game->map.map_square[(int)(game->player.pos_y)]
			[(int)(game->player.pos_x - game->player.plane_x
			* game->player.move_speed * 2)] == '0')
		game->player.pos_x -= game->player.plane_x * game->player.move_speed;
	if (game->map.map_square[(int)(game->player.pos_y - game->player.plane_y
			* game->player.move_speed * 2)]
			[(int)(game->player.pos_x)] == '0')
		game->player.pos_y -= game->player.plane_y * game->player.move_speed;
	raycasting(game);
}

void	move_right(t_game *game)
{
	if (game->map.map_square[(int)(game->player.pos_y)]
			[(int)(game->player.pos_x + game->player.plane_x
			* game->player.move_speed * 2)] == '0')
		game->player.pos_x += game->player.plane_x * game->player.move_speed;
	if (game->map.map_square[(int)(game->player.pos_y + game->player.plane_y
			* game->player.move_speed * 2)][(int)(game->player.pos_x)] == '0')
		game->player.pos_y += game->player.plane_y * game->player.move_speed;
	raycasting(game);
}
