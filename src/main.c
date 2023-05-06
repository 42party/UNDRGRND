/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/06 13:53:40 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	get_key(int keycode, t_game *game)
{
	printf("key: %i\n", keycode);
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == KEY_UP)
		move_forward(game);
	if (keycode == KEY_DOWN)
		move_backward(game);
	if (keycode == CAM_ARROW_RIGHT)
		rotate_camera_right(game);
	if (keycode == CAM_ARROW_LEFT)
		rotate_camera_left(game);
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
