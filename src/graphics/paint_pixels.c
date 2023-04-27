/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:30:23 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/27 15:17:21 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void square(t_window *win, int color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < 24)
	{
		j = 0;
		while(j < 24)
			my_mlx_pixel_put(win, j++, i, color);
		i++;
	}

}

static void paint_floor(t_window *win, char c)
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
				square(win, 0xCCCCCC);
			else if (c == '0')
				square(win, 0x964B00);
			else if (c == ' ')
				square(win, 0x000000);
			else
				square(win, 0xFF0000);
/* 			j++;
		}

		i++; */




	//create_trgb(0, maps->floor.red, maps->floor.green, maps->floor.green));
	//my_mlx_pixel_put(win, 2, 2, create_trgb(0, maps->floor.red, maps->floor.green, maps->floor.green));

}

void pait_square(t_map *maps, t_window *win)
{
	int		i;
	int		j;

	i = 0;
	while (maps->map_square[i] && i < maps->size_map)
	{
		j = 0;
		while (maps->map_square[i][j])
		{
			paint_floor(win, maps->map_square[i][j]);
			mlx_put_image_to_window(win->mlx, win->win, win->img.img, j*24,i*24);
			j++;
		}

		i++;

	}
}
