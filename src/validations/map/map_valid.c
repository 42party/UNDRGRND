/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 16:22:45 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/11 15:17:57 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int verify_content(t_map *maps, int flag)
{
	int i;
	int j;

	i = 8;
	while(i < maps->lines)
	{
		j = 0;
		while (maps->map[i][j])
		{
			if (maps->map[i] && (maps->map[i][j] == 'N'
				|| maps->map[i][j] == 'S' || maps->map[i][j] == 'W'
				|| maps->map[i][j] == 'E'))
					flag--;
			printf("SAI\n");
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
		return(ret_value(1, "Cannot put more than one position"));
	return (flag);
}

/* static int check_obliteration_map(t_map *maps)
{

} */

// static int verify_walls(t_map *maps)
// {
// 	int line;
// 	int col;

// 	line = 8;
// 	while (line <= maps->lines)
// 	{
// 		// col = 0;
// 		// while (maps->map[line][col])
// 		// {
// 		// 	if (line == 8 && (maps->map[line][col] != 32
// 		// 	|| maps->map[line][col] != 1))
// 		// 		return(ret_value(1, "Close map "));
// 		// 	// if (maps->map[line][col] == 32)
// 		// 	// 	if (check_obliteration_map(maps))
// 		// 	// 		return(ret_value(1, "Close map around spaces"));
// 		// }
// 		line ++;
// 	}
// 	return (0);
// }
// int check_map_x_y(t_map *maps)
// {
// 	verify_walls(maps);

// 			return(ret_value(1, "Only 1, 0, N, S, W, E or Spaces"));

// 	return (0);
// }

//fechar fd nos returns
// free em cada gnl
