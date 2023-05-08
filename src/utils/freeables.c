/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:41:06 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/02 10:37:11 by rgorki           ###   ########.fr       */
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
