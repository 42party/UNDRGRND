/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:01:31 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/02 13:56:42 by rgorki           ###   ########.fr       */
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

int check_map_path_texture_utils(char *temp_map_line, int flag)
{
	char	**split_line;
	size_t	size;

	split_line = ft_split(temp_map_line, 32);
	size = array_counter(split_line);
	if (!split_line || size != 2)
		return (ret_value(1, "Format incompatible: direction more path texture"));
	if (my_strncmp("NO", split_line[0]))
		if (my_strncmp("../../textures/north", split_line[1]))
			flag += 1 << 3;
	if (my_strncmp("SO", split_line[0]))
		if (my_strncmp("../../textures/south", split_line[1]))
			flag += 1 << 2;
	if (my_strncmp("WE", split_line[0]))
		if (my_strncmp("../../textures/west", split_line[1]))
			flag += 1 << 1;
	if (my_strncmp("EA", split_line[0]))
		if (my_strncmp("../../textures/east", split_line[1]))
			flag += 1 << 0;
	free_matrix(split_line);
	return (flag);
}

int	check_map_path_texture(int fd, int flag)
{
	char *temp_map_line;

	temp_map_line = get_next_line(fd);
	flag = check_map_path_texture_utils(temp_map_line, flag);
	return (flag);
}

int check_map_floor_ceilling_utils_1(char **split_numbers)
{
	int i;
	int j;

	i = 0;
	while (split_numbers[i])
		{
			j = 0;
			while(split_numbers[i])
			{
				if(my_atoi(split_numbers[i]) < 0 || my_atoi(split_numbers[i]) > 255 || !ft_isdigit(split_numbers[i][j]))
					return (ret_value(1, "Only numbers [0-255]"));
				j++;
			}
			i++;
		}
	free_matrix(split_numbers);
	return (0);
}

int check_map_floor_ceilling_utils(char **split_line, int flag)
{
	char **split_numbers;
	size_t size;

	split_numbers = ft_split(split_line[1], ',');
	size = array_counter(split_numbers);
	if (!split_numbers || size != 3)
		return (ret_value(1, "Wrong Format F or C following [0-255],[0-255],[0-255]"));
	if (my_strncmp(split_line[0], "F"))
	{
		flag += 1 << 1;
		check_map_floor_ceilling_utils_1(split_numbers);
	}
	if (my_strncmp(split_line[0], "C"))
	{
		flag += 1 << 0;
		check_map_floor_ceilling_utils_1(split_numbers);
	}
	free_matrix(split_line);
	return (flag);
}

int		check_map_floor_ceilling(int fd, int flag)
{
	char	*temp_map_line;
	char	**split_line;
	size_t	size;

	temp_map_line = get_next_line(fd);
	split_line = ft_split(temp_map_line, 32);
	size = array_counter(split_line);
	if (!split_line || size != 2)
		return (ret_value(1, "Format incompatible F or C"
					"following [0-255], [0-255], [0-255]"));
	flag += check_map_floor_ceilling_utils(split_line, flag);
	return (flag);
}

int check_map_validations(char *map_file)
{
	int fd;
	int count;
	int flag;
	char *temp_map_line;

	flag = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ret_value(1, "File does not exist"));
	count = 6;
	while(--count >= 3)
		flag += check_map_path_texture(fd, flag);
	if (flag != 15)
		return (ret_value(1, "Format NO, SO, WE, EA following path textures"));
	flag = 0;
	temp_map_line = get_next_line(fd);
	if(!my_strncmp(temp_map_line, "\n"))
		return (ret_value(1, "Need break line after direction textures"));
	while(--count)
		flag += check_map_floor_ceilling(fd, flag);
	if (flag != 3)
		return (ret_value(1, "Need one Floor and Ceilling"));
	temp_map_line = get_next_line(fd);
	if(!my_strncmp(temp_map_line, "\n"))
		return (ret_value(1, "Need break line after direction textures"));
	while (temp_map_line)
		temp_map_line = get_next_line(fd);
	close(fd);
	return (0);
}
