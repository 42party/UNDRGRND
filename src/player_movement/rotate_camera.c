/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:10:18 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/12 13:21:50 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	rotate_camera(t_game *game, double rot_speed, int dir)
{
	double	old_dir_x;
	double	old_plane_x;

	rot_speed *= dir;
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(rot_speed)
		- game->player.dir_y * sin(rot_speed);
	game->player.dir_y = old_dir_x * sin(rot_speed)
		+ game->player.dir_y * cos(rot_speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(rot_speed)
		- game->player.plane_y * sin(rot_speed);
	game->player.plane_y = old_plane_x * sin(rot_speed)
		+ game->player.plane_y * cos(rot_speed);
	raycasting(game);
}
