/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:30:23 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/26 15:32:44 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void paint_floor(t_map *maps, t_window *win, char c)
{
	(void) maps;
	int i;
	size_t j;

	i = 0;
	while(i <= maps->size_map)
	{
		j = 0;
		while (j <= maps->max_col - 1)
		{
			if (c == '1')
				my_mlx_pixel_put(win, i, j++, 0x0CC000);
			else if (c == '0')
				my_mlx_pixel_put(win, i, j++, 0xFF0000);
			else if (c == ' ')
				my_mlx_pixel_put(win, i, j++, 0x000000);
			else
				my_mlx_pixel_put(win, i, j++, 0xFFFFFF);

		}
		i++;

	}



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
			paint_floor(maps, win, maps->map_square[i][j] );
			mlx_put_image_to_window(win->mlx, win->win, win->img.img, j*20, i*20);
			j++;
		}
		i++;
	}
}
