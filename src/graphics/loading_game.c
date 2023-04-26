/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:29:36 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/25 16:07:39 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void test_print(t_map *maps, t_window *win)
{
	int i, j;
	i = j = 0;
	
	while (maps->map[i][j])
	{
		if (maps->map[i][j])
		j++;
		
	}
}

void initialize_graphics(t_map *maps, t_window *win)
{
	//paint_floor(maps, win);
	test_print(maps, win);
}
