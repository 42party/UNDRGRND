/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:13:52 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/09 13:52:37 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	get_key(int keycode, t_game *game)
{

//	printf("diry: %f\n", game->player.dirY);
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
		rotate_camera_right(game);
	if (keycode == CAM_ARROW_LEFT)
		rotate_camera_left(game);
/* 	printf("dirx: %f\n", game->player.dirX);
	printf("diry: %f\n", game->player.dirY);
	printf("planex: %f\n", game->player.planeX);
	printf("planey: %f\n\n", game->player.planeY); */
	return (0);
}