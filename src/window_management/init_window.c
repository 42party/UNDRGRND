/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:31:38 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/27 14:54:36 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_window(t_window *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx,
			DISPLAY_WIDTH, DISPLAY_HEIGHT, "fvck!");
	win->img.img = mlx_new_image(win->mlx,
			24, 24);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bits_per_pixel, &win->img.line_length,
								&win->img.endian);
}
