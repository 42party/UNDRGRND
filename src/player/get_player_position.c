/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:47:26 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/10 14:21:13 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	get_player_position(t_map *maps, t_player *player)
{
	int		i;
	int		j;

	i = 0;
	while (maps->map_square[i])
	{
		j = 0;
		while (maps->map_square[i][j])
		{
			if (maps->map_square[i][j] == 'W'
				|| maps->map_square[i][j] == 'N'
				|| maps->map_square[i][j] == 'S'
				|| maps->map_square[i][j] == 'E')
			{
				player->pos_x = j;
				player->pos_y = i;
				player->line = i;
				player->column = j;
				player->start_pos = maps->map_square[i][j];
				maps->map_square[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
