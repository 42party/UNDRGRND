/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:39:44 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/12 10:50:50 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	draw_ceiling(t_game *game, t_vars *vars, int display_x)
{
	while (vars->slice_y < vars->draw_start)
		my_mlx_pixel_put(game, display_x, vars->slice_y++, create_trgb(0,
				game->texture.ceiling.red, game->texture.ceiling.green,
				game->texture.ceiling.blue));
}

static void	draw_wall(t_game *game, t_vars *vars, int display_x)
{
	int	tex_y;
	int	color;

	tex_y = 0;
	color = 0;
	while (vars->slice_y >= vars->draw_start && vars->slice_y <= vars->draw_end)
	{
		tex_y = (int)vars->tex_pos & (game->texture.north.sprite_height - 1);
		vars->tex_pos += vars->tex_step;
		if (vars->hit_side == SIDE_X && vars->step_x > 0)
			color = get_pixel_color(game->texture.north, vars->tex_x, tex_y);
		else if (vars->hit_side == SIDE_X && vars->step_x <= 0)
			color = get_pixel_color(game->texture.south, vars->tex_x, tex_y);
		else if (vars->hit_side == SIDE_Y && vars->step_y > 0)
			color = get_pixel_color(game->texture.east, vars->tex_x, tex_y);
		else if (vars->hit_side == SIDE_Y && vars->step_y <= 0)
			color = get_pixel_color(game->texture.west, vars->tex_x, tex_y);
		my_mlx_pixel_put(game, display_x, vars->slice_y++, color);
	}
}

static void	draw_floor(t_game *game, t_vars *vars, int display_x)
{
	while (vars->slice_y < DISPLAY_HEIGHT)
		my_mlx_pixel_put(game, display_x, vars->slice_y++, create_trgb(0,
				game->texture.floor.red, game->texture.floor.green,
				game->texture.floor.blue));
}

void	draw_texturized_vertical_line(t_game *game, t_vars *vars, int display_x)
{
	draw_ceiling(game, vars, display_x);
	draw_wall(game, vars, display_x);
	draw_floor(game, vars, display_x);
}
