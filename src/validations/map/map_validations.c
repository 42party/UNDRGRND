/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:33:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/19 15:40:36 by rgorki           ###   ########.fr       */
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
		free_matrix(maps->map);
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
		free_matrix(maps->map);
		free(maps);
		return (1);
	}
	return (0);
}

int	check_map_validations(t_map *maps)
{
	if (check_map_validations_texture(maps))
		return (1);
	if (check_map_validations_ceilling(maps))
		return (1);
	if (check_map_validations_mapxy(maps))
		return (1);
	return (0);
}
