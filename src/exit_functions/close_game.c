/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:44:11 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/09 15:44:13 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int		close_game(t_window *win)
{
	//destroy e free
	mlx_destroy_image(win->mlx, win->img.img);
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
}
