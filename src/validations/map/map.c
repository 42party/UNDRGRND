/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:01:31 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/12 17:50:03 by rgorki           ###   ########.fr       */
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
	int i;

	i = 0;
	flag = 0;
	count = 0;
	while(maps->filecub[i] && count <= 3)
	{
		if (maps->filecub[i] && (!my_strncmp(maps->filecub[i], "\n")))
		{
			if (count <= 3)
				flag = check_map_path_texture(maps->filecub[count++], flag);
		}
		i++;
	}
	if (flag != 15)
		return (ret_value(1, "Format NO, SO, WE, EA following path textures"));
	maps->ctrl_line = i;
	return(0);
}

static int check_map_validations_ceilling(t_map *maps)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	if(!my_strncmp(maps->filecub[maps->ctrl_line], "\n"))
		return (ret_value(1, "Need break line after direction textures"));
	while(maps->filecub[maps->ctrl_line] && count <= 1)
	{
		if (maps->filecub[maps->ctrl_line]
			&& (!my_strncmp(maps->filecub[maps->ctrl_line], "\n")))
		{
			if (count <= 1)
			{
				flag = check_map_floor_ceilling(maps->filecub[maps->ctrl_line], flag);
				count++;
			}
		}
		maps->ctrl_line++;
	}
	if(!my_strncmp(maps->filecub[maps->ctrl_line++], "\n"))
		return (ret_value(1, "Need break line after direction textures"));
	if (flag != 3)
		return (ret_value(1, "Need one Floor and Ceilling"));
	return (0);
}

static int check_map_breakline(t_map *maps)
{
	int i;

	i = 0;
	if (maps->ctrl_line == maps->max_line)
		return (ret_value(1, "Maybe you need insert a valid map"));
	maps->size_map = maps->max_line - maps->ctrl_line;
	if (maps->size_map < 4)
		return(ret_value(1, "For a minimap valid is size 4x3"));
	maps->map = ft_calloc(sizeof(char *), maps->size_map);
	if (!maps->map)
		return (1);
	while(maps->filecub[maps->ctrl_line])
	{
		if (maps->filecub[maps->ctrl_line]
			&& (my_strncmp(maps->filecub[maps->ctrl_line], "\n")))
		{
			free_matrix(maps->map);
			return (ret_value(1, "Cannot put a breakline inside map"));
		}
		else
			maps->map[i++] = ft_strdup(maps->filecub[maps->ctrl_line++]);
	}
	return (0);
}

static int check_map_validations_mapxy(t_map *maps)
{
	int flag;

	flag = 1;
	while (maps->filecub[maps->ctrl_line]
		&& my_strncmp(maps->filecub[maps->ctrl_line], "\n"))
			maps->ctrl_line++;
	if (check_map_breakline(maps))
		return (1);
	flag = verify_content(maps, flag);
	if (flag != 0)
		return (1);
	//check_map_x_y(maps);
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
