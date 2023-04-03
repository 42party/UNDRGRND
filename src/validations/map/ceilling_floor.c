/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:29:20 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/03 12:08:34 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	check_map_floor_ceilling_utils_2(char **split_numbers)
{
	int	i;
	int	j;

	i = 0;
	while (split_numbers[i])
	{
		j = 0;
		while (split_numbers[i][j])
		{
			if (my_atoi(split_numbers[i]) < 0 ||
				my_atoi(split_numbers[i]) > 255
				|| !ft_isdigit(split_numbers[i][j]))
					return (ret_value(1, "Only numbers [0-255]"));
			j++;
		}
		i++;
	}
	free_matrix(split_numbers);
	return (0);
}

static int	check_map_floor_ceilling_utils(char **split_line, int flag)
{
	char	**split_numbers;
	char	**split_breakline;
	size_t	size;

	split_breakline = ft_split(split_line[1], 10);
	split_numbers = ft_split(split_breakline[0], 44);
	size = array_counter(split_numbers);
	if (!split_numbers || size != 3)
	{
		free_matrix(split_breakline);
		free_matrix(split_numbers);
		return (ret_value(1, "Wrong Format F or C following [0-255],[0-255],[0-255]"));
	}
	if (my_strncmp(split_line[0], "F"))
	{
		flag = 2;
		check_map_floor_ceilling_utils_2(split_numbers);
	}
	if (my_strncmp(split_line[0], "C"))
	{
		flag = 1;
		check_map_floor_ceilling_utils_2(split_numbers);
	}
	free_matrix(split_breakline);
	free_matrix(split_line);
	return (flag);
}

int	check_map_floor_ceilling(int fd, int flag)
{
	char	*temp_map_line;
	char	**split_line;
	size_t	size;

	temp_map_line = get_next_line(fd);
	split_line = ft_split(temp_map_line, 32);
	free(temp_map_line);
	size = array_counter(split_line);
	if (!split_line || size != 2)
	{
		free_matrix(split_line);
		return (ret_value(1, "Format incompatible F or C "
					"following [0-255], [0-255], [0-255]"));
	}
	flag += check_map_floor_ceilling_utils(split_line, flag);
	return (flag);
}
