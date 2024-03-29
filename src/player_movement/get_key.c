/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:13:52 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/12 13:21:43 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	get_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_UP)
		move_forward(game);
	if (keycode == KEY_DOWN)
		move_backward(game);
	if (keycode == KEY_LEFT)
		move_left(game);
	if (keycode == KEY_RIGHT)
		move_right(game);
	if (keycode == CAM_ARROW_RIGHT)
		rotate_camera(game, game->player.rot_speed, DIR_RIGHT);
	if (keycode == CAM_ARROW_LEFT)
		rotate_camera(game, game->player.rot_speed, DIR_LEFT);
	return (0);
}
