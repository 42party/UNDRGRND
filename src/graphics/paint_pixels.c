/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:30:23 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/25 15:07:13 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void paint_floor(t_map *maps, t_window *win)
{
	(void) maps;
	int i;

	i = 0;
	while(i < DISPLAY_HEIGHT)
	{
		my_mlx_pixel_put(win, i, i, 0xFF0000);
		i++;

	}

	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);

	//create_trgb(0, maps->floor.red, maps->floor.green, maps->floor.green));
	//my_mlx_pixel_put(win, 2, 2, create_trgb(0, maps->floor.red, maps->floor.green, maps->floor.green));

}
