/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:01:31 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/02 11:01:46 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int check_map_extension(char *map_name)
{
	char	*extension;
	char	*temp_name;
	int		result;

	if (!map_name)
		return (ret_value(1, "Missing map name: format namefile.cub"));
	extension = ".cub";
	temp_name = ft_strrchr(map_name, '.');
	result = ft_strncmp(temp_name, extension, 5);
	return (result);
}

void check_map_validations()
{

}
