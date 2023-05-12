/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:06:55 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/12 10:29:47 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	get_addr_locale(t_data img, int x, int y)
{
	return (y * img.line_length + x * (img.bits_per_pixel / 8));
}

t_uint	get_pixel_color(t_data	img, int x, int y)
{
	char	*dest;

	dest = img.addr + get_addr_locale(img, x, y);
	return (*(unsigned int *)dest);
}
