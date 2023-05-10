/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:28:57 by sxpph             #+#    #+#             */
/*   Updated: 2023/05/10 09:37:32 by vipereir         ###   ########.fr       */
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

//	init_vars(game);
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

        cameraX = 2 * x / (double)DISPLAY_WIDTH - 1;
		
		// calcula direção do raio
		rayDirX = game->player.dirX + game->player.planeX * cameraX;
		rayDirY = game->player.dirY + game->player.planeY * cameraX;


		// posição no mapa em int
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

		// side dist é a distancia do Player para o proximo x ou y

		// delta dist é a distancia de um X ou Y para o proximo x ou y
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


		// ccalcula exetamente aonde o raio bateu na parede.
		double wallX;

		if (side == SIDE_X)
			wallX = game->player.posY + perpWallDist * rayDirY;
		else
			wallX = game->player.posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		int	texX;

		texX = (int)(wallX * (double)game->texture.north.sprite_width);
		if (side == SIDE_X && rayDirX > 0)
			texX = game->texture.north.sprite_width - texX - 1;
		if (side == SIDE_Y && rayDirY < 0)
			texX = game->texture.north.sprite_width - texX - 1;

		double step;

		step = 1.0 * game->texture.north.sprite_height / line_height;
		
		double textPos;

		textPos = (draw_start - DISPLAY_HEIGHT / 2 + line_height / 2) * step;

		draw_texturized_vertical_line(x, draw_start, draw_end, step, textPos, side, texX, game, rayDirX, rayDirY);
		
        x += 1;
    }

	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx,game->img.img);
    game->img.img = mlx_new_image(game->mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    
    return (0);
}