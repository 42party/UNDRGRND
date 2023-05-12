/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/12 10:30:30 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

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
	game.map = *maps;
	game.player = *players;
	init_game(&game);
	mlx_hook(game.win, CLICK_X, 0, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, get_key, &game);
	initialize_graphics(&game);
	mlx_loop(game.mlx);
	free_maps(maps);
	free(players);
	return (0);
}
