/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:17:40 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/06 21:00:52 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dest;

	//dest = game->img.addr + (y * game->img.line_length + x * (game->img.bits_per_pixel / 8));
	dest = game->img.addr + get_addr_locale(game->img, x, y);
	*(unsigned int*)dest = color;
}
