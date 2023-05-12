/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:52:18 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/12 10:55:54 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	ray_direction(t_game *game, t_vars *vars, int x)
{
	vars->camera_x = 2 * x / (double)DISPLAY_WIDTH - 1;
	vars->ray_dir_x = game->player.dir_x + game->player.plane_x
		* vars->camera_x;
	vars->ray_dir_y = game->player.dir_y + game->player.plane_y
		* vars->camera_x;
}

void	calc_delta_dist(t_game *game, t_vars *vars)
{
	if (vars->ray_dir_x == 0)
		vars->delta_dist_x = 1e30;
	else
		vars->delta_dist_x = sqrt(1 + (pow(vars->ray_dir_y, 2)
					/ pow(vars->ray_dir_x, 2)));
	if (vars->ray_dir_y == 0)
		vars->delta_dist_y = 1e30;
	else
		vars->delta_dist_y = sqrt(1 + (pow(vars->ray_dir_x, 2)
					/ pow(vars->ray_dir_y, 2)));
	game->player.map_x = (int)game->player.pos_x;
	game->player.map_y = (int)game->player.pos_y;
}

void	calc_side_dist(t_game *game, t_vars *vars)
{
	if (vars->ray_dir_x < 0)
	{
		vars->step_x = -1;
		vars->side_dist_x = (game->player.pos_x - game->player.map_x)
			* vars->delta_dist_x;
	}
	else
	{
		vars->step_x = +1;
		vars->side_dist_x = (game->player.map_x + 1.0 - game->player.pos_x)
			* vars->delta_dist_x;
	}
	if (vars->ray_dir_y < 0)
	{
		vars->step_y = -1;
		vars->side_dist_y = (game->player.pos_y - game->player.map_y)
			* vars->delta_dist_y;
	}
	else
	{
		vars->step_y = +1;
		vars->side_dist_y = (game->player.map_y + 1.0 - game->player.pos_y)
			* vars->delta_dist_y;
	}
}

void	dda_rasterizer(t_game *game, t_vars *vars)
{
	while (666)
	{
		if (vars->side_dist_x < vars->side_dist_y)
		{
			vars->hit_side = SIDE_X;
			vars->side_dist_x += vars->delta_dist_x;
			game->player.map_x += vars->step_x;
		}
		else
		{
			vars->hit_side = SIDE_Y;
			vars->side_dist_y += vars->delta_dist_y;
			game->player.map_y += vars->step_y;
		}
		if (game->map.map_square[game->player.map_y][game->player.map_x] != '0')
			break ;
	}
}

void	wall_size(t_vars *vars)
{
	if (vars->hit_side == SIDE_X)
		vars->perp_wall_dist = vars->side_dist_x - vars->delta_dist_x;
	else
		vars->perp_wall_dist = vars->side_dist_y - vars->delta_dist_y;
	vars->line_height = (int)(DISPLAY_HEIGHT / vars->perp_wall_dist);
	vars->draw_start = -vars->line_height / 2 + DISPLAY_HEIGHT / 2;
	if (vars->draw_start < 0)
		vars->draw_start = 0;
	vars->draw_end = vars->line_height / 2 + DISPLAY_HEIGHT / 2;
	if (vars->draw_end >= DISPLAY_HEIGHT)
		vars->draw_end = DISPLAY_HEIGHT - 1;
}
