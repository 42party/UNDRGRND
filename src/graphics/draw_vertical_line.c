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

void    draw_texturized_vertical_line(int  display_x, int draw_start,
            int draw_end, double step, double textPos, int side, int texX, t_game *game)
{
    int y;
    int texY;
    int color;

    y = 0;
    while (y < draw_start)
        my_mlx_pixel_put(game, display_x, y++, create_trgb(0,
             game->texture.ceiling.red, game->texture.ceiling.green,
             game->texture.ceiling.blue));
    while (y >= draw_start && y <= draw_end)
    {
        texY = (int)textPos & (game->texture.north.sprite_height - 1);
        textPos += step;
        color = get_pixel_color(game->texture.north, texX, texY);
        if (side == SIDE_Y)
            color = (color >> 1) & 8355711; // macete pra escurecer a cor.
        my_mlx_pixel_put(game, display_x, y++, color);
    }
    while (y < DISPLAY_HEIGHT)
        my_mlx_pixel_put(game, display_x, y++, create_trgb(0,
             game->texture.floor.red, game->texture.floor.green,
             game->texture.floor.blue));
}