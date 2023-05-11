/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:33:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/10 14:16:10 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void free_textures_floor(t_map *maps)
{
	if (maps->textures && maps->textures[0])
		free(maps->textures[0]);
	if (maps->textures && maps->textures[1])
		free(maps->textures[1]);
	if (maps->textures && maps->textures[2])
		free(maps->textures[2]);
	if (maps->textures && maps->textures[3])
		free(maps->textures[3]);
	if (maps->floor_ceilling && maps->floor_ceilling[0])
		free(maps->floor_ceilling[0]);
	if (maps->floor_ceilling && maps->floor_ceilling[1])
		free(maps->floor_ceilling[1]);
	free(maps->textures);
	free(maps->floor_ceilling);
}

int	validations(t_map *maps, char **argv)
{
	if (check_map_extension(argv[1]))
	{
		free(maps);
		return (1);
	}
	if (get_line_map(maps, argv[1]))
	{
		free_matrix(maps->map);
		return (1);
	}
	if (get_info_map(maps, argv[1]))
	{
		free_matrix(maps->filecub);
		free_matrix(maps->map);
		return (1);
	}
	if (check_map_validations(maps))
	{
		free_matrix(maps->filecub);
		free_textures_floor(maps);
		free_matrix(maps->map);
		free(maps);
		return (1);
	}
	return (0);
}

static void loop_aux_texture(t_map *maps, char *split_0, char *split_1)
{
	if (my_strncmp("NO", split_0))
	{
		if(!maps->textures[0])
			maps->textures[0] = ft_strjoin("NO ", split_1);
		maps->count_texture++;
		maps->flag += 8;
	}
	if (my_strncmp("SO", split_0))
	{
		if(!maps->textures[1])
			maps->textures[1] = ft_strjoin("SO ", split_1);
		maps->count_texture++;
		maps->flag += 4;
	}
	if (my_strncmp("WE", split_0))
	{
		if(!maps->textures[2])
			maps->textures[2] = ft_strjoin("WE ", split_1);
		maps->count_texture++;
		maps->flag += 2;
	}
	if (my_strncmp("EA", split_0))
	{
		if(!maps->textures[3])
			maps->textures[3] = ft_strjoin("EA ", split_1);
		maps->count_texture++;
		maps->flag += 1;
	}
}

static void loop_aux_floor_ceiling(t_map *maps, char **split, char *str)
{
	if (split && my_strncmp("F", split[0]))
	{
		if(!maps->floor_ceilling[0])
			maps->floor_ceilling[0] = ft_strdup(str);
		maps->count_fc++;
		maps->flag += 16;
	}
	if (split && my_strncmp("C", split[0]))
	{
		if(!maps->floor_ceilling[1])
			maps->floor_ceilling[1] = ft_strdup(str);
		maps->count_fc++;
		maps->flag += 32;
	}

}

int separete_cub(t_map *maps)
{
	char	**split_line;
	int		i;

	i = 0;
	split_line = ft_split(maps->filecub[i], 32);
	while(maps->filecub[i])
	{
		if (split_line && split_line[0][0] != '\n' && array_counter(split_line) == 2)
			loop_aux_texture(maps, split_line[0], split_line[1]);
		if (split_line && split_line[0][0] != '\n' && array_counter(split_line) >= 2)
			loop_aux_floor_ceiling(maps, split_line, maps->filecub[i]);
		if (split_line && split_line[0][0] != '\n' && array_counter(split_line) == 1
			&& maps->flag != 63)
		{
			free_matrix(split_line);
			return (ret_value(1, "Map position only end of file or "
						 "textures floor ceiling repeating"));
		}
		if (split_line && split_line[0][0] != '\n' && array_counter(split_line) == 1)
		{
			free_matrix(split_line);
			maps->ctrl_line = i;
			return (0);
		}
		free_matrix(split_line);
		i++;
		split_line = ft_split(maps->filecub[i], 32);
	}
	free_matrix(split_line);
	return (0);
}

int	check_map_validations(t_map *maps)
{
	maps->flag = 0;
	maps->textures = ft_calloc(sizeof(char *), 5);
	maps->floor_ceilling = ft_calloc(sizeof(char *), 3);
	if (!maps->textures || !maps->floor_ceilling)
		exit(1);
	maps->count_fc = 0;
	maps->count_texture = 0;

	if (separete_cub(maps) || maps->count_fc != 2 || maps->count_texture != 4 || maps->flag != 63)
		return (1);
	if (check_map_validations_texture(maps))
		return (1);
	if (check_map_validations_ceilling(maps))
		return (1);
	if (check_map_validations_mapxy(maps))
		return (1);

	return (0);
}
