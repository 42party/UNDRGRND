/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/06 21:01:50 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

// ligar o -Werror no makefile

int	main(int argc, char **argv)
{
	t_map		*maps;
	t_game		game;
	t_player	*players;

	// verification
	argc_verify(argc);
	maps = malloc(sizeof(t_map));
	if (validations(maps, argv))
		exit(1);
	// player and map setup
	players = malloc(sizeof(t_player));
	square_map(maps);
	get_player_position(maps, players);
	game.map = *maps;
	game.player = *players;
	// initial win config
	init_game(&game);
	// mlx hooks
	mlx_hook(game.win, CLICK_X, 0, close_game, &game);
	mlx_hook(game.win, 2, 1L<<0, get_key, &game);
	// init graphs
	initialize_graphics(&game);
	// mlx main loop
	mlx_loop(game.mlx);
	// frees
	free_maps(maps);
	free(players);
	return (0);
}
