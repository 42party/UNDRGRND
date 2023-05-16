/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:22:45 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/16 14:24:22 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	pulse(char x)
{
	if (x == '0' || x == 'N' || x == 'S' || x == 'E' || x == 'W')
		return (1);
	return (0);
}

int	verify_content(t_map *maps, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (i < maps->size_map - 1)
	{
		j = 0;
		while (maps->map[i][j])
		{
			if (maps->map[i] && (maps->map[i][j] == 'N'
				|| maps->map[i][j] == 'S' || maps->map[i][j] == 'W'
				|| maps->map[i][j] == 'E'))
					flag--;
			if (maps->map[i] && (maps->map[i][j] != 32
				&& maps->map[i][j] != '1' && maps->map[i][j] != '0'
				&& maps->map[i][j] != 'N' && maps->map[i][j] != 'S'
				&& maps->map[i][j] != 'W' && maps->map[i][j] != 'E' ))
				return (ret_value(1, "Only 1, 0, N, S, W, E or Spaces"));
			j++;
		}
		i++;
	}
	if (flag != 0)
		return (ret_value(1, "Need a position (N, S, W, or E)"));
	return (flag);
}

int	check_map_x_y(t_map *maps)
{
	if (radar_validation(maps))
		return (ret_value(1, "Close map around spaces"));
	free_matrix(maps->temp_map);
	return (0);
}
