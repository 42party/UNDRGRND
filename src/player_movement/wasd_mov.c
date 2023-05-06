/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:09:33 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/06 13:46:13 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void    move_forward(t_game *game)
{
	if (game->map.map_square[(int)(game->player.posY)][(int)(game->player.posX + game->player.dirX * game->player.moveSpeed)] == '0')
		game->player.posX += game->player.dirX * game->player.moveSpeed;
	if (game->map.map_square[(int)(game->player.posY + game->player.dirY * game->player.moveSpeed)][(int)(game->player.posX)] == '0')
		game->player.posY += game->player.dirY * game->player.moveSpeed;
	raycasting(game);
}

void    move_backward(t_game *game)
{
	if (game->map.map_square[(int)(game->player.posY)][(int)(game->player.posX - game->player.dirX * game->player.moveSpeed)] == '0')
		game->player.posX -= game->player.dirX * game->player.moveSpeed;
	if (game->map.map_square[(int)(game->player.posY - game->player.dirY * game->player.moveSpeed)][(int)(game->player.posX)] == '0')
		game->player.posY -= game->player.dirY * game->player.moveSpeed;
	raycasting(game);
}

/* void    move_left(t_game *game)
{

}

void    move_right(t_game *game)
{

} */
