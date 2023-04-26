/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:47:26 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/26 14:37:27 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// faça uma função que procure x em um arry de caracteres

#include	"../header/cub3d.h"

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
				player->posX = maps->map_square[i];
				player->posY = maps->map_square[i][j];

			}
			j++;
		}

		i++;
	}
	// return (-1);
}
