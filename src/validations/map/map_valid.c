/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:22:45 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/18 11:44:11 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int verify_content(t_map *maps, int flag)
{
	int i;
	int j;

	i = 0;
	while(i < maps->size_map - 1)
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
					return(ret_value(1, "Only 1, 0, N, S, W, E or Spaces"));
			j++;
		}
		i++;
	}
	if (flag != 0)
		return(ret_value(1, "Need a position (N, S, W, or E)"));
	return (flag);
}

static int verify_walls(t_map *maps)
{
 	int line;
 	int col;

 	line = 8;
 	while (line <= maps->size_map)
 	{
 		 col = 0;
 		 while (maps->map[line][col])
 		 {
 		 	if (line == 8)
 		 			return(ret_value(1, "Close map "));
 		 	 if (maps->map[line][col] == 32)
 		 	 		return(ret_value(1, "Close map around spaces"));
 		 }
 		line ++;
 	}
 	return (0);
 }
 int check_map_x_y(t_map *maps)
 {
 	verify_walls(maps);
		return(ret_value(1, "Only 1, 0, N, S, W, E or Spaces"));

	free_matrix(maps->temp_map);
 	return (0);
 }
