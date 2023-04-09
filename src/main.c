/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/09 15:41:58 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

/* static void validations(char **argv)
{
	if (check_map_validations(argv[1]))
		printf("VALIDATIONS");
} */

int	get_key(int keycode, t_window *win)
{
	(void)win;
	printf("keycode: %i\n", keycode);
	if (keycode == KEY_ESC)
		close_game(win);
	return (0);
}

int main(int argc, char **argv)
{
//	validations(argv);
	t_window	win;
	(void)argc;
	(void)argv;

	// gerando a tela
	init_window(&win);
	// laod game

	// key hooks
	mlx_hook(win.win, CLICK_X, 0, close_game, &win);
	mlx_key_hook(win.win, get_key, &win);
	mlx_loop(win.mlx);
	return (0);
}

