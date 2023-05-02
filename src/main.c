/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/02 15:41:30 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	get_key(int keycode, t_game *game)
{

	double moveSpeed = 0.3;
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_UP)
	{
		if (game->map.map_square[(int)(game->player.posY)][(int)(game->player.posX + game->player.dirX * moveSpeed)] == '0')
			game->player.posX += game->player.dirX * moveSpeed;
		if (game->map.map_square[(int)(game->player.posY + game->player.dirY * moveSpeed)][(int)(game->player.posX)] == '0')
			game->player.posY += game->player.dirY * moveSpeed;
		raycasting(game);
	}
	if (keycode == KEY_DOWN)
	{
		if (game->map.map_square[(int)(game->player.posY)][(int)(game->player.posX - game->player.dirX * moveSpeed)] == '0')
			game->player.posX -= game->player.dirX * moveSpeed;
		if (game->map.map_square[(int)(game->player.posY - game->player.dirY * moveSpeed)][(int)(game->player.posX)] == '0')
			game->player.posY -= game->player.dirY * moveSpeed;
		raycasting(game);
	}

	double rotSpeed = 0.3;

	if (keycode == KEY_RIGHT)
	{
		double oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(-rotSpeed) - game->player.dirY * sin(-rotSpeed);
		game->player.dirY = oldDirX * sin(-rotSpeed) + game->player.dirY * cos(-rotSpeed);
		double oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(-rotSpeed) - game->player.planeY * sin(-rotSpeed);
		game->player.planeY = oldPlaneX * sin(-rotSpeed) + game->player.planeY * cos(-rotSpeed);
		raycasting(game);
	}
	if (keycode == KEY_LEFT)
	{
		double oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(rotSpeed) - game->player.dirY * sin(rotSpeed);
		game->player.dirY = oldDirX * sin(rotSpeed) + game->player.dirY * cos(rotSpeed);
		double oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(rotSpeed) - game->player.planeY * sin(rotSpeed);
		game->player.planeY = oldPlaneX * sin(rotSpeed) + game->player.planeY * cos(rotSpeed);
		raycasting(game);
	}

	//	move_player(game, &(game)->player, &(game)->map, 1);
/* 	//	move_player(game, &(game)->player, &(game)->map, 0);
	if (keycode == KEY_RIGHT)
		move_player(game, &(game)->player, &(game)->map, 1);
	//	move_player(game, &(game)->player, &(game)->map, 2);
	if (keycode == KEY_UP) */
	//	move_player(game, &(game)->player, &(game)->map, 13);
	//mlx_clear_window(game->mlx,game->win);
	//pait_square(&game->map, win);
	//mlx_put_image_to_window(game->mlx, game->win, game->img.img, (win)->player.line*20, (win)->player.column*20);

	return (0);
}

int	main(int argc, char **argv)
{
	t_map		*maps;
	t_game		game;
	t_player	*players;

	argc_verify(argc);
	maps = malloc(sizeof(t_map));
	if (validations(maps, argv))
		exit(1);
	players = malloc(sizeof(t_player));
	square_map(maps);
	get_player_position(maps, players);
	init_game(&game);
	load_game(&game);
	game.map = *maps;
	game.player = *players;
	mlx_hook(game.win, CLICK_X, 0, close_game, &game);
	mlx_hook(game.win, 2, 1L<<0, get_key, &game);
	initialize_graphics(maps, &game);
	mlx_loop(game.mlx);
	free_maps(maps);
	free(players);
	return (0);
}
