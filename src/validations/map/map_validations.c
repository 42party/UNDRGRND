/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:33:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/15 10:37:51 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	validations(t_map *maps, char **argv)
{
	if (check_map_extension(argv[1]))
	{
		free(maps);
		return (1);
	}
	if (get_line_map(maps, argv[1]))
	{
		free(maps);
		return (1);
	}
	if (get_info_map(maps, argv[1]))
	{
		free_matrix(maps->filecub);
		free_matrix(maps->map);
		return (1);
	}
	if (check_map_validations(maps))
	{
		free_matrix(maps->filecub);
		free_textures_floor(maps);
		free(maps);
		return (1);
	}
	return (0);
}

static int	check_texture_extension(t_map *maps)
{
	int	i;

	i = 0;
	while (maps->textures[i])
	{
		if (check_xpm_extension(maps->textures[i++]))
			return (1);
	}
	return (0);
}

int	check_map_validations(t_map *maps)
{
	maps->flag = 0;
	maps->textures = ft_calloc(sizeof(char *), 5);
	maps->floor_ceilling = ft_calloc(sizeof(char *), 3);
	if (!maps->textures || !maps->floor_ceilling)
		exit(1);
	maps->count_fc = 0;
	maps->count_texture = 0;
	if (separete_cub(maps) || maps->count_fc != 2
		|| maps->count_texture != 4 || maps->flag != 63)
		return (1);
	if (check_texture_extension(maps))
		return (1);
	if (check_map_validations_texture(maps))
		return (1);
	if (check_map_validations_ceilling(maps))
		return (1);
	if (check_map_validations_mapxy(maps))
	{
		free_matrix(maps->map);
		return (1);
	}
	return (0);
}
