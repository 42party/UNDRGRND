/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separete.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 06:39:36 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/18 09:13:10 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	loop_aux_texture(t_map *maps, char *split_0, char *split_1)
{
	if (my_strncmp("NO", split_0))
	{
		if (!maps->textures[0])
			maps->textures[0] = ft_strjoin("NO ", split_1);
		maps->count_texture++;
		maps->flag += 8;
	}
	if (my_strncmp("SO", split_0))
	{
		if (!maps->textures[1])
			maps->textures[1] = ft_strjoin("SO ", split_1);
		maps->count_texture++;
		maps->flag += 4;
	}
	if (my_strncmp("WE", split_0))
	{
		if (!maps->textures[2])
			maps->textures[2] = ft_strjoin("WE ", split_1);
		maps->count_texture++;
		maps->flag += 2;
	}
	aux_loop_texture(maps, split_0, split_1);
}

static void	loop_aux_floor_ceiling(t_map *maps, char **split, char *str)
{
	if (split && my_strncmp("F", split[0]))
	{
		if (!maps->floor_ceilling[0])
			maps->floor_ceilling[0] = ft_strdup(str);
		maps->count_fc++;
		maps->flag += 16;
	}
	if (split && my_strncmp("C", split[0]))
	{
		if (!maps->floor_ceilling[1])
			maps->floor_ceilling[1] = ft_strdup(str);
		maps->count_fc++;
		maps->flag += 32;
	}
}

static int	aux_separete(t_map *maps, char **split_line, int i)
{
	if (split_line && split_line[0][0] != '\n'
				&& ft_isdigit(split_line[0][0]))
	{
		free_matrix(split_line);
		maps->ctrl_line = i;
		return (1);
	}
	free_matrix(split_line);
	return (0);
}

static void	aux_loop_separete(t_map *maps, char **split_line, int i)
{
	if (split_line && split_line[0][0] != '\n'
		&& array_counter(split_line) == 2)
		loop_aux_texture(maps, split_line[0], split_line[1]);
	if (split_line && split_line[0][0] != '\n'
		&& array_counter(split_line) >= 2)
		loop_aux_floor_ceiling(maps, split_line, maps->filecub[i]);
}

int	separete_cub(t_map *maps)
{
	char	**split_line;
	int		i;

	i = 0;
	split_line = ft_split(maps->filecub[i], 32);
	while (maps->filecub[i])
	{
		aux_loop_separete(maps, split_line, i);
		if (split_line && split_line[0][0] != '\n'
			&& ft_isdigit(split_line[0][0]) && maps->flag != 63)
		{
			free_matrix(split_line);
			return (ret_value(1, "Map position only end of file or "
					"textures floor ceiling repeating"));
		}
		if (aux_separete(maps, split_line, i))
			return (0);
		i++;
		split_line = ft_split(maps->filecub[i], 32);
	}
	free_matrix(split_line);
	return (0);
}
