/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:51:17 by sxpph             #+#    #+#             */
/*   Updated: 2023/05/01 11:21:14 by sxpph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void    draw_vertical_line(int  display_x, int draw_start,
            int draw_end, int color, t_game *game)
{
     int y;

    y = 0;

    //printf("aaggggsdfas\n");
 //   printf("y: %i, draw_start %i, draw_end %i\n", y, draw_start, draw_end);

    while (y < DISPLAY_HEIGHT)
    {
        if (y >= draw_start && y <= draw_end)
            my_mlx_pixel_put(game, 0, y, color);
   //     else 
   //         my_mlx_pixel_put(game, 0, y, 0xFF0000);
 //       printf("y: %i\n", y);
        y++;
    }

	mlx_put_image_to_window(game->mlx, game->win, game->img.img, display_x, 0);
 //   usleep(1000);
    mlx_destroy_image(game->mlx,game->img.img);
    game->img.img = mlx_new_image(game->mlx, 1, DISPLAY_HEIGHT);
 //   printf("saiu\n");

}