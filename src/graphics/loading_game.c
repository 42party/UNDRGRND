/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:29:36 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/29 11:51:01 by sxpph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_player(t_game	*game)
{
	// inicializando com valores de teste;
	game->player.posX = 16;
	game->player.posY = 2;
	game->player.dirX = 0;
	game->player.dirY = -1;
	game->player.planeX = 0;
	game->player.planeY = 0.666;
	game->fps.time = 0;
	game->fps.old_time = 0;
}

void initialize_graphics(t_map *maps, t_game *game)
{
	(void)game;
	(void)maps;
	init_player(game);


//	while (666)
		raycasting(game);
}


//	paint_floor(maps, game);
//	pait_square(maps, game);