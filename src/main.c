/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/10 14:22:52 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static int validations(t_map *maps, char **argv)
{
	if (check_map_extension(argv[1]))
		return (1);
	if (get_line_map(maps, argv[1]))
		return (1);
	if (get_info_map(maps, argv[1]))
		return (1);
	 if (check_map_validations(maps))
		return (1);
	return (0);
}

static void free_maps(t_map *maps)
{
	free_matrix(maps->map);
	free(maps);
}

static void argc_verify(int argc)
{
	if (argc != 2)
	{
		printf("Invalid map or format\n");
		printf("example: ./cub3D src/maps/mapname.cub\n");
		exit(1);
	}
}

int main(int argc, char **argv)
{
	t_map *maps;

	argc_verify(argc);
	maps = malloc(sizeof(t_map));
	if (validations(maps, argv))
	{
		free_maps(maps);
		exit(1);
	}
	int i ;
	i = 0;
	while(maps->map[i])
		printf("%s\n", maps->map[i++]);

	free_maps(maps);
	return (0);
}
