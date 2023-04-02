/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:01:31 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/02 17:59:28 by rgorki           ###   ########.fr       */
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
		return (ret_value(1, "Format NO, SO, WE, EA following path textures"));
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

static int verify_content(char *line, int count)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while(line[i] && line[i] == 10)
	{
		if (line[i] && line[i] == 32)
			i++;
		else if (line[i] && (line[i] == '1' || line[i] == '0'))
			i++;
		else if(line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
			count--;

	}

	return (0);
}

static int check_map_x_y(int fd)
{
	char	*temp_map_line;
	int		lines;
	int		count;

	lines = 0;
	count = 1;
	temp_map_line = get_next_line(fd);
	while (temp_map_line)
	{
		if (verify_content(temp_map_line, count))
			return(ret_value(1, "Only 1, 0, N, S, W, E or Spaces"));
		free(temp_map_line);
		temp_map_line = get_next_line(fd);
		lines++;
	}
	if (count != 0)
		return(ret_value(1, "Cannot put more than one position"));

	return (0);
}

//fechar fd nos returns
// free em cada gnl

int check_map_validations(char *map_file)
{
	int fd;
	char *temp_map_line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ret_value(1, "File does not exist"));
	if(check_map_validations_utils(fd))
		return (1);
	temp_map_line = get_next_line(fd);
	if(!my_strncmp(temp_map_line, "\n"))
		return (ret_value(1, "Need break line after direction textures"));
	if(check_map_validations_utils_2(fd))
		return (1);
	temp_map_line = get_next_line(fd);
	if(!my_strncmp(temp_map_line, "\n"))
		return (ret_value(1, "Need break line after direction textures"));
	if(check_map_x_y(fd))
		return (1);
	close(fd);
	return (0);
}
