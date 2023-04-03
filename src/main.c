/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/03 13:00:39 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static int validations(t_map *map, char **argv)
{
	(void)map;
	if (check_map_extension(argv[1]))
		return (1);
	if (get_info_maps(map, argv[1]))
		return (1);
	if (check_map_validations(argv[1]))
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	(void)argc;
	if (validations(map, argv))
	{
		free(map);
		exit(1);
	}

	free(map);
	return (0);
}
