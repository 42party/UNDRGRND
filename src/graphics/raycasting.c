/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:28:57 by sxpph             #+#    #+#             */
/*   Updated: 2023/05/10 14:21:58 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	ray_direction(t_game *game, t_vars *vars, int x)
{
	vars->camera_x = 2 * x / (double)DISPLAY_WIDTH - 1;
	vars->ray_dir_x = game->player.dir_x + game->player.plane_x * vars->camera_x;
	vars->ray_dir_y = game->player.dir_y + game->player.plane_y * vars->camera_x;
}

void	calc_delta_dist(t_game *game, t_vars *vars)
{
	// delta dist é a distancia entre um x e outro x;
	if (vars->ray_dir_x != 0)
		vars->delta_dist_x = sqrt(1 + (pow(vars->ray_dir_y, 2) / pow(vars->ray_dir_x, 2)));
	if (vars->ray_dir_y != 0)
		vars->delta_dist_y = sqrt(1 + (pow(vars->ray_dir_x, 2) / pow(vars->ray_dir_y, 2)));
}

void	calc_side_dist(t_game *game, t_vars *vars)
{
// side dist é a distancia da onde o raio partiu até ele bater;
// side dist é a distancia do Player para o proximo x ou y
// delta dist é a distancia de um X ou Y para o proximo x ou y

	game->player.map_x = (int)game->player.pos_x;
	game->player.map_y = (int)game->player.pos_y;
	if (vars->ray_dir_x < 0)
	{
		vars->step_x = -1;
		vars->side_dist_x = (game->player.pos_x - game->player.map_x) * vars->delta_dist_x;
	}
	else
	{
		vars->step_x = +1;
		vars->side_dist_x = (game->player.map_x + 1.0 - game->player.pos_x) * vars->delta_dist_x;
	}
	if (vars->ray_dir_y < 0)
	{
		vars->step_y = -1;
		vars->side_dist_y = (game->player.pos_y - game->player.map_y) * vars->delta_dist_y;
	}
	else
	{
		vars->step_y = +1;
		vars->side_dist_y = (game->player.map_y + 1.0 - game->player.pos_y) * vars->delta_dist_y;
	}
}

dda_rasterizer(t_game *game, t_vars *vars)
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
		if (game->map.map_square[game->player.map_y][game->player.map_x] != 0)
			break ;
	}
}

void	wall_size(t_game *game, t_vars *vars)
{
	if (vars->hit_side == SIDE_X)
		vars->perp_wall_dist = vars->side_dist_x - vars->delta_dist_x;
	else
		vars->perp_wall_dist = vars->side_dist_y - vars->delta_dist_y;
	//printf("perp_wall_dist: %f\n", vars->perp_wall_dist); // tira isso.
	vars->line_height = DISPLAY_HEIGHT / vars->perp_wall_dist;
	vars->draw_start = -vars->line_height / 2 + DISPLAY_HEIGHT / 2;
	if (vars->draw_start < 0)
		vars->draw_start = 0;
	vars->draw_end = vars->line_height / 2 + DISPLAY_HEIGHT / 2;
	if (vars->draw_end >= DISPLAY_HEIGHT)
		vars->draw_end = DISPLAY_HEIGHT - 1;
}

void	calc_texture_x(t_game *game, t_vars *vars)
{
	// ccalcula exetamente aonde o raio bateu na parede.
	if (vars->hit_side == SIDE_X)
		vars->wall_x = game->player.pos_y + vars->perp_wall_dist * vars->ray_dir_y;
	else
		vars->wall_x = game->player.pos_x + vars->perp_wall_dist * vars->ray_dir_x;
	vars->wall_x -= floor(vars->wall_x);
	vars->tex_x = (int)(vars->wall_x * (double)game->texture.north.sprite_width);
	if (vars->hit_side == SIDE_X && vars->ray_dir_x > 0)
		vars->tex_x = game->texture.north.sprite_width - vars->tex_x - 1;
	if (vars->hit_side == SIDE_Y && vars->ray_dir_y < 0)
		vars->tex_x = game->texture.north.sprite_width - vars->tex_x - 1;
	vars->tex_step = 1.0 * game->texture.north.sprite_height / vars->line_height;
	vars->tex_pos = (vars->draw_start - DISPLAY_HEIGHT / 2 + vars->line_height / 2) * vars->tex_step;
}

int raycasting(t_game *game)
{
    int 	x;
	t_vars	vars;
	
    x = 0;
    while (x < DISPLAY_WIDTH)
    {
		ft_bzero(&vars, sizeof(t_vars));
		ray_direction(game, &vars, x);
		calc_delta_dist(game, &vars);
		calc_side_dist(game, &vars);
		dda_rasterizer(game, &vars);
		wall_size(game, &vars);	
		calc_texture_x(game, &vars);
		draw_texturized_vertical_line(game, &vars, x);
        x += 1;
    }
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx,game->img.img);
    game->img.img = mlx_new_image(game->mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    return (0);
}