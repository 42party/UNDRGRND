/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:33:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/19 14:09:36 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	free_validation(t_map *maps, int flag)
{
	if (flag == 0)
		return (0);
	if (flag == 1)
		return (1);
	if (flag > 1)
		free_matrix(maps->filecub);
	if (flag > 2)
		free_matrix(maps->map);
	free(maps);
	return (1);
}

int	validations(t_map *maps, char **argv)
{
	int	flag;

	flag = 0;
	if (check_map_extension(argv[1]))
		flag += 1;
	if (get_line_map(maps, argv[1]))
		flag += 1;
	if (get_info_map(maps, argv[1]))
		flag += 2;
	if (check_map_validations(maps))
		flag += 3;
	free_validation(maps, flag);
	return (flag);
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
