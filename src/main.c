/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/27 15:07:49 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	get_key(int keycode, t_window *win)
{
	if (keycode == KEY_ESC)
		close_game(win);
	if (keycode == KEY_LEFT)
		move_player(win, &(win)->player, &(win)->map, 0);
	if (keycode == KEY_DOWN)
		move_player(win, &(win)->player, &(win)->map, 1);
	if (keycode == KEY_RIGHT)
		move_player(win, &(win)->player, &(win)->map, 2);
	if (keycode == KEY_UP)
		move_player(win, &(win)->player, &(win)->map, 13);
	//mlx_clear_window(win->mlx,win->win);
	//pait_square(&win->map, win);
	//mlx_put_image_to_window(win->mlx, win->win, win->img.img, (win)->player.line*20, (win)->player.column*20);

	return (0);
}

int	main(int argc, char **argv)
{
	t_map		*maps;
	t_window	win;
	t_player	*players;

	argc_verify(argc);
	maps = malloc(sizeof(t_map));
	players = malloc(sizeof(t_player));
	if (validations(maps, argv))
		exit(1);
	square_map(maps);
	get_player_position(maps, players);
	init_window(&win);
	load_game(&win);
	win.map = *maps;
	win.player = *players;
	mlx_hook(win.win, CLICK_X, 0, close_game, &win);
	mlx_key_hook(win.win, get_key, &win);
	initialize_graphics(maps, &win);
	mlx_loop(win.mlx);

	free_maps(maps);
	return (0);
}
