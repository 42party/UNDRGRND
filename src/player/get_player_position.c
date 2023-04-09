/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:47:26 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/09 17:50:06 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// faça uma função que procure x em um arry de caracteres

#include "../header/cub3d.h"

void	get_player_possition(char **map, int lines)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == PLAYER)
			{
				printf("possition %i\n", (i * lines + j));
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	//return (-1);
}
