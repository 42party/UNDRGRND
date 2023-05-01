/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:28:57 by sxpph             #+#    #+#             */
/*   Updated: 2023/05/01 11:24:31 by sxpph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int raycasting(t_game *game)
{
    (void)game;
    int x;
    x = 0;

    while (x < DISPLAY_WIDTH)
    {

    double  cameraX = 0;
    double  rayDirX = 0;
    double  rayDirY = 0;

	double	sideDistX = 0;
	double	sideDistY = 0;

	double	deltaDistX = 0;
	double	deltaDistY = 0;

    double	perpWallDist = 0;

	int		stepX =0;
	int		stepY = 0;

	int		hit = 0;
	int		side = 0;

	int		line_height = 0;
	int		draw_start = 0;
	int		draw_end = 0;

	int		color = 0;


        cameraX = 2 * x / (double)DISPLAY_WIDTH - 1;
		rayDirX = game->player.dirX + game->player.planeX * cameraX;
		rayDirY = game->player.dirY + game->player.planeY * cameraX;

		game->player.mapX = (int)game->player.posX;
		game->player.mapY = (int)game->player.posY;

		if (rayDirX == 0)
			deltaDistX = 1e30;
		else
			deltaDistX = sqrt(1 + (pow(rayDirY, 2) / pow(rayDirX, 2))); // da pra simplificar;
		if (rayDirY == 0)
			deltaDistY = 1e30;
		else
			deltaDistY = sqrt(1 + (pow(rayDirX, 2) / pow(rayDirY, 2)));

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->player.posX - game->player.mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (game->player.mapX + 1.0 - game->player.posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->player.posY - game->player.mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (game->player.mapY + 1.0 - game->player.posY) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				game->player.mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				game->player.mapY += stepY;
				side = 1;
			}
			if (game->map.map_square[game->player.mapY][game->player.mapX] != '0')
				hit = 1;
		}

		if (side == SIDE_X) // esse side checa se bateu em x ou y, posso usar um define pro 0 e 1
			perpWallDist = sideDistX - deltaDistX;
		else
			perpWallDist = sideDistY - deltaDistY;
		

		line_height = (int)(DISPLAY_HEIGHT / perpWallDist);
		draw_start = -line_height / 2 + DISPLAY_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + DISPLAY_HEIGHT / 2;
		if (draw_end >= DISPLAY_HEIGHT)
			draw_end = DISPLAY_HEIGHT - 1;

		if (side == 0)
			color = 0x00FF00;
		else
			color = 0x0000FF;
		
		draw_vertical_line(x, draw_start, draw_end, color, game);
        x++;
    }

	//mlx_put_image_to_window(game->mlx, game->win, game->img.img, x, 0);
    
    return (0);
}
//printf("ray: %f\n", rayDirY);
