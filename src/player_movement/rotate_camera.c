/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:10:18 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/06 13:54:57 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void    rotate_camera_right(t_game *game)
{
    double oldDirX;
    double oldPlaneX;

	oldDirX = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(-game->player.rotSpeed) - game->player.dirY * sin(-game->player.rotSpeed);
	game->player.dirY = oldDirX * sin(-game->player.rotSpeed) + game->player.dirY * cos(-game->player.rotSpeed);
	oldPlaneX = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(-game->player.rotSpeed) - game->player.planeY * sin(-game->player.rotSpeed);
	game->player.planeY = oldPlaneX * sin(-game->player.rotSpeed) + game->player.planeY * cos(-game->player.rotSpeed);
	raycasting(game);
}

void    rotate_camera_left(t_game *game)
{
    double oldDirX;
    double oldPlaneX;

	oldDirX = game->player.dirX;
	game->player.dirX = game->player.dirX * cos(game->player.rotSpeed) - game->player.dirY * sin(game->player.rotSpeed);
	game->player.dirY = oldDirX * sin(game->player.rotSpeed) + game->player.dirY * cos(game->player.rotSpeed);
    oldPlaneX = game->player.planeX;
	game->player.planeX = game->player.planeX * cos(game->player.rotSpeed) - game->player.planeY * sin(game->player.rotSpeed);
	game->player.planeY = oldPlaneX * sin(game->player.rotSpeed) + game->player.planeY * cos(game->player.rotSpeed);
	raycasting(game);
}

