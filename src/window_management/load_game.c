/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:56:30 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/19 14:37:02 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	lines_counter(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	collumns_counter(char **map)
{
	int	j;
	int	i;
	int	bigger_line;

	i = 0;
	j = 0;
	bigger_line = 0;
	while (map[i])
	{
		while (map[i][j])
			j++;
		i++;
		if (j > bigger_line)
			bigger_line = j;
		j = 0;
	}
	return (bigger_line);
}

void	load_game(t_window *win)
{
	(void)win;

	//	int	lines;
	//	int	collumns;
	//	lines = lines_counter((char **)map);
	//	collumns = collumns_counter((char **)map);
	//	printf("lines %i\n", lines);
	//	printf("cols %i\n", collumns);
	//	get_player_possition((char **)map, lines);
}

