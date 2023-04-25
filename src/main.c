/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/25 13:56:04 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	get_key(int keycode, t_window *win)
{
	(void)win;
	if (keycode == KEY_ESC)
		close_game(win);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map		*maps;
	t_window	win;

	argc_verify(argc);
	maps = malloc(sizeof(t_map));
	if (validations(maps, argv))
		exit(1);
	init_window(&win);
	load_game(&win);

	mlx_hook(win.win, CLICK_X, 0, close_game, &win);
	mlx_key_hook(win.win, get_key, &win);
	initialize_graphics(maps, &win);
	mlx_loop(win.mlx);

	free_maps(maps);
	return (0);
}
