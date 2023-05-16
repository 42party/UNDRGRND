/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:57:00 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/16 14:23:59 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static char	*fill_space(char *str, int max_col)
{
	int		len;
	char	*temp_str;

	len = ft_strlen(str);
	temp_str = my_realloc(str, max_col + 2);
	while (len < max_col + 1)
		temp_str[len++] = 32;
	return (temp_str);
}

static void	fill_topdown(t_map *maps)
{
	int	max_size;
	int	last_line;

	last_line = maps->size_map;
	max_size = maps->max_col + 1;
	maps->temp_map[0] = ft_calloc(sizeof(char), max_size);
	maps->temp_map[last_line] = ft_calloc(sizeof(char), max_size);
	maps->temp_map[0] = fill_space(maps->temp_map[0], max_size);
	maps->temp_map[last_line] = fill_space(maps->temp_map[last_line], max_size);
}

int	clone_map(t_map *maps)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 1;
	maps->temp_map = ft_calloc(sizeof(char *), maps->size_map + 2);
	if (!maps->temp_map)
		return (1);
	fill_topdown(maps);
	while (maps->map[i] && i < maps->size_map)
	{
		temp = ft_strjoin(" ", maps->map[i]);
		maps->temp_map[j++] = fill_space(temp, maps->max_col + 1);
		i++;
	}
	maps->tmp_max_line = array_counter(maps->temp_map) - 1;
	maps->tmp_max_col = ft_strlen(maps->temp_map[0]);
	return (0);
}

static int	radar_pulse(t_map *maps, int line, int col)
{
	if (maps->temp_map[line])
	{
		if (line != 0 && col != 0 && pulse(maps->temp_map[line - 1][col - 1]))
			return (1);
		if (col != 0 && pulse(maps->temp_map[line][col - 1]))
			return (1);
		if (line < maps->tmp_max_line && col != 0
			&& pulse(maps->temp_map[line + 1][col - 1]))
			return (1);
		if (line != 0 && pulse(maps->temp_map[line - 1][col]))
			return (1);
		if (pulse(maps->temp_map[line][col]))
			return (1);
		if (line < maps->tmp_max_line && pulse(maps->temp_map[line + 1][col]))
			return (1);
		if (line != 0 && col < maps->tmp_max_col
			&& pulse(maps->temp_map[line - 1][col + 1]))
			return (1);
		if (col < maps->tmp_max_col && pulse(maps->temp_map[line][col + 1]))
			return (1);
		if (line < maps->tmp_max_line && col < maps->tmp_max_col
			&& pulse(maps->temp_map[line + 1][col + 1]))
			return (1);
	}
	return (0);
}

int	radar_validation(t_map *maps)
{
	int	line;
	int	col;
	int	flag;
	int	max_col;

	flag = 0;
	line = 0;
	max_col = ft_strlen(maps->temp_map[0]);
	while (maps->temp_map[line])
	{
		col = 0;
		while (col < max_col)
		{
			if (maps->temp_map[line][col] == ' ')
				flag = radar_pulse(maps, line, col);
			if (flag == 1)
				return (ret_value(1, "Close walls"));
			col++;
		}
		line++;
	}
	return (0);
}
