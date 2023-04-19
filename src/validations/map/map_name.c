/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:44:54 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/19 15:24:16 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	check_map_extension(char *map_name)
{
	char	*extension;
	char	*temp_name;

	if (!map_name)
		return (ret_value(1, "Missing map name: format namefile.cub"));
	extension = ".cub";
	temp_name = ft_strrchr(map_name, '.');
	if (!my_strncmp(temp_name, extension))
		return (ret_value(1, "Missing map name: format namefile.cub"));
	return (0);
}
