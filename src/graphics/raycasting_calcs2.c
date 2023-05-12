/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calcs2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:52:15 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/12 10:57:07 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	set_values(t_vars *vars)
{
	vars->camera_x = 0;
	vars->ray_dir_x = 0;
	vars->ray_dir_y = 0;
	vars->side_dist_x = 0;
	vars->side_dist_y = 0;
	vars->delta_dist_x = 0;
	vars->delta_dist_y = 0;
	vars->perp_wall_dist = 0;
	vars->step_x = 0;
	vars->step_y = 0;
	vars->hit_side = 0;
	vars->line_height = 0;
	vars->draw_start = 0;
	vars->draw_end = 0;
	vars->wall_x = 0;
	vars->tex_x = 0;
	vars->tex_step = 0;
	vars->tex_pos = 0;
	vars->slice_y = 0;
}

void	calc_texture_x(t_game *game, t_vars *vars)
{
	if (vars->hit_side == SIDE_X)
		vars->wall_x = game->player.pos_y + vars->perp_wall_dist
			* vars->ray_dir_y;
	else
		vars->wall_x = game->player.pos_x + vars->perp_wall_dist
			* vars->ray_dir_x;
	vars->wall_x -= floor(vars->wall_x);
	vars->tex_x = (int)(vars->wall_x
			*(double)game->texture.north.sprite_width);
	if (vars->hit_side == SIDE_X && vars->ray_dir_x > 0)
		vars->tex_x = game->texture.north.sprite_width - vars->tex_x - 1;
	if (vars->hit_side == SIDE_Y && vars->ray_dir_y < 0)
		vars->tex_x = game->texture.north.sprite_width - vars->tex_x - 1;
	vars->tex_step = 1.0 * game->texture.north.sprite_height
		/ vars->line_height;
	vars->tex_pos = (vars->draw_start - DISPLAY_HEIGHT
			/ 2 + vars->line_height / 2) * vars->tex_step;
}
