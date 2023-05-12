/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:29:20 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/12 13:26:52 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	loop_check_floor_ceilling(char **split_numbers, int i)
{
	int	ret_value;

	ret_value = my_atoi(split_numbers[i]);
	if (ret_value < 0 || ret_value > 255)
		return (1);
	return (0);
}

static void	floor_ceiling_color(t_map *maps, char **split_numbers,
		char floor_ceiling, int i)
{
	if (floor_ceiling == 'C')
	{
		if (i == 1)
			maps->ceiling.red = ft_atoi(split_numbers[i]);
		else if (i == 2)
			maps->ceiling.green = ft_atoi(split_numbers[i]);
		else
			maps->ceiling.blue = ft_atoi(split_numbers[i]);
	}
	else if (floor_ceiling == 'F')
	{
		if (i == 1)
			maps->floor.red = ft_atoi(split_numbers[i]);
		else if (i == 2)
			maps->floor.green = ft_atoi(split_numbers[i]);
		else
			maps->floor.blue = ft_atoi(split_numbers[i]);
	}
}

static int	check_map_floor_ceilling_utils_2(t_map *maps, char **split_numbers)
{
	int	i;

	i = 1;
	while (split_numbers[i])
	{
		if (loop_check_floor_ceilling(split_numbers, i))
			return (ret_value(1, "Format incompatible F or C "
					"following [0-255], [0-255], [0-255]"));
		floor_ceiling_color(maps, split_numbers, split_numbers[0][0], i);
		i++;
	}
	return (0);
}

static int	check_map_floor_ceilling_utils(t_map *maps, char **split_line)
{
	if (check_map_floor_ceilling_utils_2(maps, split_line))
	{
		free_matrix(split_line);
		return (1);
	}
	free_matrix(split_line);
	return (0);
}

int	check_map_floor_ceilling(t_map *maps, char *map)
{
	char	**split_line;
	size_t	size;

	split_line = ft_split_mod(map);
	size = array_counter(split_line);
	if (!split_line || size != 4)
	{
		free_matrix(split_line);
		return (ret_value(1, "Format incompatible F or C "
				"following [0-255], [0-255], [0-255]"));
	}
	if (check_map_floor_ceilling_utils(maps, split_line))
		return (1);
	return (0);
}
