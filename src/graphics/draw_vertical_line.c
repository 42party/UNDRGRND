/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:51:17 by sxpph             #+#    #+#             */
/*   Updated: 2023/05/01 14:49:38by sxpph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void    draw_vertical_line(int  display_x, int draw_start,
            int draw_end, int color, t_game *game)
{
    int y;

    y = 0;
    while (y < draw_start)
        my_mlx_pixel_put(game, display_x, y++, create_trgb(0,
             game->texture.ceiling.red, game->texture.ceiling.green,
             game->texture.ceiling.blue));
    while (y >= draw_start && y <= draw_end)
        my_mlx_pixel_put(game, display_x, y++, color);
    while (y < DISPLAY_HEIGHT)
        my_mlx_pixel_put(game, display_x, y++, create_trgb(0,
             game->texture.floor.red, game->texture.floor.green,
             game->texture.floor.blue));
}

void    draw_texturized_vertical_line(t_game *game, t_vars *vars, int display_x)
{
    int y;
    int tex_y;
    int color;

    y = 0;
    while (y < vars->draw_start)
        my_mlx_pixel_put(game, display_x, y++, create_trgb(0,
             game->texture.ceiling.red, game->texture.ceiling.green,
             game->texture.ceiling.blue) * 0);
    while (y >= vars->draw_start && y <= vars->draw_end)
    {
        tex_y = (int)vars->tex_pos & (game->texture.north.sprite_height - 1);
        vars->tex_pos += vars->tex_step;
        if (vars->hit_side == SIDE_X && vars->ray_dir_x) // poderia usar step_x e step_y
            color = get_pixel_color(game->texture.north, vars->tex_x, tex_y);
        else if (vars->hit_side == SIDE_X && vars->ray_dir_x <= 0)
            color = get_pixel_color(game->texture.south, vars->tex_x, tex_y);
        else if (vars->hit_side == SIDE_Y && vars->ray_dir_y > 0)
            color = get_pixel_color(game->texture.east, vars->tex_x, tex_y);
        else if (vars->hit_side == SIDE_Y && vars->ray_dir_y <= 0)
            color = get_pixel_color(game->texture.west, vars->tex_x, tex_y);
          //  color = (color >> 1) & 8355711; // macete pra escurecer a cor.
        my_mlx_pixel_put(game, display_x, y++, color);
    }
    while (y < DISPLAY_HEIGHT)
        my_mlx_pixel_put(game, display_x, y++, create_trgb(0,
             game->texture.floor.red, game->texture.floor.green,
             game->texture.floor.blue) * 0);
}