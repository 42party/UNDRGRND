/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:41:06 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/26 09:08:00 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	free_maps(t_map *maps)
{
	free_matrix(maps->filecub);
	free_matrix(maps->map);
	free_matrix(maps->map_square);
	free(maps);
}
