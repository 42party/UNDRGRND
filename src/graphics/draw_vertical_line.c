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

    while (y < DISPLAY_HEIGHT)
    {
        if (y >= draw_start && y <= draw_end)
        {
            my_mlx_pixel_put(game, display_x, y, color);
        }
//        else 
//            my_mlx_pixel_put(game, display_x, y, 0xFF0000);
        y += 1; // pode ser usado pra abaixar a resoluçaõ
    }
}