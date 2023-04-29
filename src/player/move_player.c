/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:51:26 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/29 11:09:42 by sxpph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	check_move(char c)
{
	if (c == '1')
		return (0);
	if (c == '0')
		return (1);
	return (0);
}

static void	destroy_put_walk(t_game *game, t_map *maps, t_player *players, int keycode)
{
	maps->map_square[players->line][players->column] = '0';
	square(game, 0x964B00);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, players->column*24,players->line*24);
	if (keycode == 0)
		players->column -= 1;
	if (keycode == 1)
		players->line += 1;
	if (keycode == 2)
		players->column += 1;
	if (keycode == 13)
		players->line -= 1;
	maps->map_square[players->line][players->column] = 'P';
	square(game, 0xFF0000);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, players->column*24,players->line*24);
	printf("player: line: %i - column %i\n", players->line, players->column);
}
int	move_player(t_game *game, t_player *players, t_map *maps, int keycode)
{
	if (keycode == 0)
		if (check_move(maps->map_square[players->line][players->column - 1]))
			destroy_put_walk(game, maps, players, keycode);
	if (keycode == 1)
		if (check_move(maps->map_square[players->line + 1][players->column]))
			destroy_put_walk(game, maps, players, keycode);
	if (keycode == 2)
		if (check_move(maps->map_square[players->line][players->column + 1]))
			destroy_put_walk(game, maps, players, keycode);
	if (keycode == 13)
		if (check_move(maps->map_square[players->line - 1][players->column]))
			destroy_put_walk(game, maps, players, keycode);
	return (0);
}

