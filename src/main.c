/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/29 11:12:56 by sxpph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	get_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_LEFT)
		move_player(game, &(game)->player, &(game)->map, 0);
	if (keycode == KEY_DOWN)
		move_player(game, &(game)->player, &(game)->map, 1);
	if (keycode == KEY_RIGHT)
		move_player(game, &(game)->player, &(game)->map, 2);
	if (keycode == KEY_UP)
		move_player(game, &(game)->player, &(game)->map, 13);
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
	players = malloc(sizeof(t_player));
	if (validations(maps, argv))
		exit(1);
	square_map(maps);
	get_player_position(maps, players);
	init_game(&game);
	load_game(&game);
	game.map = *maps;
	game.player = *players;
	mlx_hook(game.win, CLICK_X, 0, close_game, &game);
	mlx_key_hook(game.win, get_key, &game);
	initialize_graphics(maps, &game);
	
	mlx_loop(game.mlx);

	free_maps(maps);
	return (0);
}
