/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceilling_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:29:20 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/09 15:44:25 by rgorki           ###   ########.fr       */
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
	int  number;
	int		i;
	int		j;

	number = 0;
	 i = 1;
	 size = array_counter(split_line);
	 while(split_line[i])
	 {
		j = 0;
		while (split_line[i][j] && split_line[i][j] != ',')
		{
			number = number + (split_line[i][j++] - '0');
			number = number * 10;
		}
		if (split_line[i][j] && split_line[i][j] == ',' || i == size - 1)
		{
			if (split_line[0][0] == 'C')
				if (maps->ceiling.red == -1)
					maps->ceiling.red = number;
				if (maps->ceiling.green == -1)
					maps->ceiling.green = number;
				if (maps->ceiling.blue == -1)
					maps->ceiling.blue = number;
			if (split_line[0][0] == 'F')
				if (maps->floor.red == -1)
					maps->floor.red = number;
				if (maps->floor.green == -1)
					maps->floor.green = number;
				if (maps->floor.blue == -1)
					maps->floor.blue = number;
			number = 0;
			printf("num: %d i: %i size: %i\n", number, i , size);
		}

		i++;
	 }

	printf("cred %d\n", maps->ceiling.red);
	printf("cgreen %d\n", maps->ceiling.green);
	printf("cblue %d\n\n", maps->ceiling.blue);
	printf("fred %d\n", maps->floor.red);
	printf("fgreen %d\n", maps->floor.green);
	printf("fblue %d\n\n", maps->floor.blue);

	size = array_counter(split_numbers);

	if (!split_numbers)
	{
		free_ceilling_utils(split_breakline, split_numbers);
		return (1);
	}
	check_map_floor_ceilling_utils_2(maps, split_numbers, split_line[0][0]);
	free_ceilling_utils(split_breakline, split_line);
	return (flag);
}

int	check_map_floor_ceilling(t_map *maps, char *map, int flag)
{
	char	**split_line;
	size_t	size;

	split_line = ft_split(map, 32);
	size = array_counter(split_line);
	if (!split_line)
	{
		free_matrix(split_line);
		return (1);
	}
	flag += check_map_floor_ceilling_utils(maps, split_line, flag);
	return (flag);
}
