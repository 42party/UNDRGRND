/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:31:38 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/09 15:41:14 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_window(t_window *win)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT, "fvck!"); // mudar nome para cub3D
	win->img.img = mlx_new_image(win->mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT);
}


