/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:01:31 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/10 15:21:46 by rgorki           ###   ########.fr       */
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

static int check_map_validations_texture(t_map *maps)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	while (count <= 3)
		flag = check_map_path_texture(maps->map[count++], flag);
	if (flag != 15)
		return (ret_value(1, "Format NO, SO, WE, EA following path textures"));
	return(0);
}

static int check_map_validations_ceilling(t_map *maps)
{
	int	count;
	int	flag;

	flag = 0;
	count = 5;
	if(!my_strncmp(maps->map[4], "\n"))
		return (ret_value(1, "Need break line after direction textures"));
	while(count < 7)
		flag = check_map_floor_ceilling(maps->map[count++], flag);
	if(!my_strncmp(maps->map[7], "\n"))
		return (ret_value(1, "Need break line after direction textures"));
	if (flag != 3)
		return (ret_value(1, "Need one Floor and Ceilling"));
	return (0);
}

static int check_map_validations_mapxy(t_map *maps)
{

	return (0);
}

int check_map_validations(t_map *maps)
{
	if(check_map_validations_texture(maps))
		return (1);
	if(check_map_validations_ceilling(maps))
		return (1);
	if(check_map_validations_mapxy(maps))
		return (1);
	return (0);
}
