/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/16 10:47:01 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	main(int argc, char **argv)
{
	t_game		game;

	argc_verify(argc);
	if (validations(&((((((game.map)))))), argv))
		exit(1);
	square_map(&game.map);
	get_player_position(&game.map, &game.player);
	init_game(&game);
	mlx_hook(game.win, CLICK_X, 0, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, get_key, &game);
	initialize_graphics(&game);
	mlx_loop(game.mlx);
	return (0);
}
