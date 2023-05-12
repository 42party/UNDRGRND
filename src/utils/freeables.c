/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:41:06 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/12 13:26:30 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	free_maps(t_map *maps)
{
	free_matrix(maps->textures);
	free_matrix(maps->floor_ceilling);
	free_matrix(maps->map_square);
	free_matrix(maps->filecub);
	free_matrix(maps->map);
	free(maps);
}

void	free_textures_floor(t_map *maps)
{
	if (maps->textures && maps->textures[0])
		free(maps->textures[0]);
	if (maps->textures && maps->textures[1])
		free(maps->textures[1]);
	if (maps->textures && maps->textures[2])
		free(maps->textures[2]);
	if (maps->textures && maps->textures[3])
		free(maps->textures[3]);
	if (maps->floor_ceilling && maps->floor_ceilling[0])
		free(maps->floor_ceilling[0]);
	if (maps->floor_ceilling && maps->floor_ceilling[1])
		free(maps->floor_ceilling[1]);
	free(maps->textures);
	free(maps->floor_ceilling);
}
