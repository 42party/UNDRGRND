/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:01:31 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/03 13:02:31 by rgorki           ###   ########.fr       */
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

static int check_map_validations_utils(int fd)
{
	int	count;
	int	flag;

	flag = 0;
	count = 4;
	while (count--)
		flag = check_map_path_texture(fd, flag);
	if (flag != 15)
	{
		close(fd);
		return (ret_value(1, "Format NO, SO, WE, EA following path textures"));
	}
	return(0);
}

static int check_map_validations_utils_2(int fd)
{
	int	count;
	int	flag;

	flag = 0;
	count = 2;
	while(count--)
		flag = check_map_floor_ceilling(fd, flag);
	if (flag != 3)
		return (ret_value(1, "Need one Floor and Ceilling"));
	return (0);
}

int check_map_validations(char *map_file)
{
	int fd;
	char *temp_map_line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (ret_value(1, "File does not exist"));
	}
	if(check_map_validations_utils(fd))
	{
		close(fd);
		return (1);
	}
	temp_map_line = get_next_line(fd);
	if(!my_strncmp(temp_map_line, "\n"))
	{
		free(temp_map_line);
		close(fd);
		return (ret_value(1, "Need break line after direction textures"));
	}
	free(temp_map_line);
	if(check_map_validations_utils_2(fd))
	{
		close(fd);
		return (1);
	}
	temp_map_line = get_next_line(fd);
	if(!my_strncmp(temp_map_line, "\n"))
	{
		free(temp_map_line);
		return (ret_value(1, "Need break line after direction textures"));
	}
	free(temp_map_line);
	close(fd);
	return (0);
}
