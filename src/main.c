/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/13 16:15:47 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	get_key(int keycode, t_window *win)
{
	(void)win;
	//printf("keycode: %i\n", keycode);
	if (keycode == KEY_ESC)
		close_game(win);
	return (0);
}

static int free_validation(t_map *maps, int flag)
{
	if (flag == 0)
		return (0);
	if (flag == 1)
		return (1);
	if (flag > 1)
		free_matrix(maps->filecub);
	if (flag > 2)
		free_matrix(maps->map);
	free(maps);
	return (1);
}

static int validations(t_map *maps, char **argv)
{
	int	flag;

	flag = 0;
	if (check_map_extension(argv[1]))
		flag += 1;
	if (get_line_map(maps, argv[1]))
		flag += 1;
	if (get_info_map(maps, argv[1]))
		flag += 1;
	 if (check_map_validations(maps))
		flag += 1;
	free_validation(maps, flag);
	return (flag);
}



static void free_maps(t_map *maps)
{
	free_matrix(maps->filecub);
	free(maps);
}

static void argc_verify(int argc)
{
	if (argc != 2)
	{
		printf("Invalid map or format\n");
		printf("example: ./cub3D src/maps/mapname.cub\n");
		exit(1);
	}
}

int main(int argc, char **argv)
{
	t_map *maps;
    t_window	win;

	argc_verify(argc);
	maps = malloc(sizeof(t_map));
	if (validations(maps, argv))
		exit(1);
	free_matrix(maps->map);
	free_maps(maps);



	// gerando a tela
	init_window(&win);
	load_game(&win);

	// key hookaaaas
	mlx_hook(win.win, CLICK_X, 0, close_game, &win);
	mlx_key_hook(win.win, get_key, &win);
	mlx_loop(win.mlx);

	return (0);
}
