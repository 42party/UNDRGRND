/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:57:00 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/03 11:45:10 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int get_info_maps(t_map *map, char *map_file)
{
	int fd;
	char *temp_map_line;

	map->lines = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ret_value(1, "File does not exist"));
	temp_map_line = get_next_line(fd);
	map->lines++;
	while(temp_map_line)
	{
		free(temp_map_line);
		temp_map_line = get_next_line(fd);
		map->lines++;
	}
	free(temp_map_line);
	close(fd);
	if (map->lines < 11)
		return (1);
	return (0);
}
