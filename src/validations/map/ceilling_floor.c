/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:29:20 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/25 12:45:15 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int loop_check_floor_ceilling(char **split_numbers, int i, int j)
{
	if (my_atoi(split_numbers[i]) < 0
		|| my_atoi(split_numbers[i]) > 255
		|| !ft_isdigit(split_numbers[i][j]))
			return (1);
	return (0);
}

static void floor_ceiling_color(t_map *maps, char **split_numbers, char floor_ceiling, int i)
{
	if (floor_ceiling == 'C')
	{
		if (i == 0)
			maps->ceiling.red = ft_atoi(split_numbers[i]);
		else if (i == 1)
			maps->ceiling.green = ft_atoi(split_numbers[i]);
		else
			maps->ceiling.blue = ft_atoi(split_numbers[i]);
	}
	else if (floor_ceiling == 'F')
	{
		if (i == 0)
			maps->floor.red = ft_atoi(split_numbers[i]);
		else if (i == 1)
			maps->floor.green = ft_atoi(split_numbers[i]);
		else
			maps->floor.blue = ft_atoi(split_numbers[i]);
	}
}

static int	check_map_floor_ceilling_utils_2(t_map *maps, char **split_numbers, char floor_ceiling)
{
	int	i;
	int	j;

	i = 0;
	while (split_numbers[i])
	{
		j = 0;
		while (split_numbers[i][j])
		{
			if (loop_check_floor_ceilling(split_numbers, i, j++))
				return (ret_value(1, "Only numbers [0-255]"));
		}
		floor_ceiling_color(maps, split_numbers, floor_ceiling, i);
		i++;
	}
	free_matrix(split_numbers);
	return (0);
}

static void	free_ceilling_utils(char **split, char **split_utils)
{
	free_matrix(split);
	free_matrix(split_utils);
}

static int	check_map_floor_ceilling_utils(t_map *maps, char **split_line, int flag)
{
	char	**split_numbers;
	char	**split_breakline;
	size_t	size;

	split_breakline = ft_split(split_line[1], 10);
	split_numbers = ft_split(split_breakline[0], 44);
	size = array_counter(split_numbers);
	if (!split_numbers || size != 3)
	{
		free_ceilling_utils(split_breakline, split_numbers);
		return (ret_value(1, "Wrong Format F or C following"
				"[0-255],[0-255],[0-255]"));
	}
	if (my_strncmp(split_line[0], "F"))
	{
		flag = 2;
		check_map_floor_ceilling_utils_2(maps, split_numbers, split_line[0][0]);
	}
	if (my_strncmp(split_line[0], "C"))
	{
		flag = 1;
		check_map_floor_ceilling_utils_2(maps, split_numbers, split_line[0][0]);
	}
	free_ceilling_utils(split_breakline, split_line);
	return (flag);
}

int	check_map_floor_ceilling(t_map *maps, char *map, int flag)
{
	char	**split_line;
	size_t	size;

	split_line = ft_split(map, 32);
	size = array_counter(split_line);
	if (!split_line || size != 2)
	{
		free_matrix(split_line);
		return (ret_value(1, "Format incompatible F or C "
				"following [0-255], [0-255], [0-255]"));
	}
	flag += check_map_floor_ceilling_utils(maps, split_line, flag);
	return (flag);
}
