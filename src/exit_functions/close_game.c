/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:44:11 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/16 10:44:23 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	close_game(t_game *game)
{
	free_maps(&game->map);
	mlx_destroy_image(game->mlx, game->texture.north.img);
	mlx_destroy_image(game->mlx, game->texture.south.img);
	mlx_destroy_image(game->mlx, game->texture.west.img);
	mlx_destroy_image(game->mlx, game->texture.east.img);
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
