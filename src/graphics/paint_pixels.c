/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxpph <sxpph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:30:23 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/29 11:08:12 by sxpph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void square(t_game *game, int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < 24)
	{
		j = 0;
		while(j < 24)
			my_mlx_pixel_put(game, j++, i, color);
		i++;
	}

}

static void paint_floor(t_game *game, char c)
{
/* 	int i;
	size_t j;

	i = 0; */
/* 	while(i <= maps->size_map)
	{
		j = 0;
		while (j <= maps->max_col - 1)
		{ */
			if (c == '1')
				square(game, 0xCCCCCC);
			else if (c == '0')
				square(game, 0x964B00);
			else if (c == ' ')
				square(game, 0x000000);
			else
				square(game, 0xFF0000);
/* 			j++;
		}

		i++; */




	//create_trgb(0, maps->floor.red, maps->floor.green, maps->floor.green));
	//my_mlx_pixel_put(win, 2, 2, create_trgb(0, maps->floor.red, maps->floor.green, maps->floor.green));

}

void pait_square(t_map *maps, t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (maps->map_square[i] && i < maps->size_map)
	{
		j = 0;
		while (maps->map_square[i][j])
		{
			paint_floor(game, maps->map_square[i][j]);
			mlx_put_image_to_window(game->mlx, game->win, game->img.img, j*24,i*24);
			j++;
		}

		i++;

	}
}
