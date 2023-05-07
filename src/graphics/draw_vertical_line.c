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