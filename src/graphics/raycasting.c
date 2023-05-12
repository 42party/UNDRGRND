/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:18:51 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/12 10:56:51 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	raycasting(t_game *game)
{
	int		x;
	t_vars	vars;

	x = 0;
	while (x < DISPLAY_WIDTH)
	{
		set_values(&vars);
		ray_direction(game, &vars, x);
		calc_delta_dist(game, &vars);
		calc_side_dist(game, &vars);
		dda_rasterizer(game, &vars);
		wall_size(&vars);
		calc_texture_x(game, &vars);
		draw_texturized_vertical_line(game, &vars, x);
		x += 1;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx, game->img.img);
	game->img.img = mlx_new_image(game->mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	return (0);
}
