/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:33:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/19 15:40:36 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

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
		free_matrix(maps->textures);
		free_matrix(maps->floor_ceilling);
		free_matrix(maps->map);
		free(maps);
		return (1);
	}
	return (0);
}

static int loop_aux_texture(t_map *maps, char *split_0, char *split_1, int flag)
{
	if (my_strncmp("NO", split_0) && !maps->textures[0])
	{
		maps->textures[0] = ft_strjoin("NO ", split_1);
		return (flag = 8);
	}
	if (my_strncmp("SO", split_0) && !maps->textures[1])
	{
		maps->textures[1] = ft_strjoin("SO ", split_1);
		return (flag = 4);
	}
	if (my_strncmp("WE", split_0) && !maps->textures[2])
	{
		maps->textures[2] = ft_strjoin("WE ", split_1);
		return (flag = 2);
	}
	if (my_strncmp("EA", split_0) && !maps->textures[3])
	{
		maps->textures[3] = ft_strjoin("EA ", split_1);
		return (flag = 1);
	}
}

static int loop_aux_floor_ceiling(t_map *maps, char *split_0, char *split_1, int flag)
{
	if (my_strncmp("F", split_0) && !maps->floor_ceilling[0])
	{
		maps->floor_ceilling[0] = ft_strjoin("F ", split_1);
		return (flag = 16);
	}
	if (my_strncmp("C", split_0) && !maps->floor_ceilling[1])
	{
		maps->floor_ceilling[1] = ft_strjoin("C ", split_1);
		return (flag = 32);
	}
}

int separete_cub(t_map *maps)
{
	char	**split_line;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	split_line = ft_split(maps->filecub[i], 32);
	while(maps->filecub[i])
	{

		if (split_line && split_line[0][0] != '\n' && array_counter(split_line) == 2)
			flag += loop_aux_texture(maps, split_line[0], split_line[1], flag);
		if (split_line && split_line[0][0] != '\n' && array_counter(split_line) == 2)
			flag += loop_aux_floor_ceiling(maps, split_line[0], split_line[1], flag);

		printf("%s \n", maps->filecub[i]);
		if (split_line && split_line[0][0] != '\n' && array_counter(split_line) == 1
			&& flag != 63)
		{
			free_matrix(split_line);
			return (ret_value(1, "Map position only end of file or"
						 "textures floor ceiling repeating"));
		}
		if (flag == 63 && split_line[0][0] != '\n' && array_counter(split_line) == 1)
		{
			free_matrix(split_line);
			return (i);
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
	int ret;

	ret = 0;
	maps->textures = ft_calloc(sizeof(char *), 4);
	maps->floor_ceilling = ft_calloc(sizeof(char *), 3);
	if (!maps->textures || !maps->floor_ceilling)
		exit(1);
	ret += separete_cub(maps);
	printf("ret: %i\n", ret);
	if (ret == 1)
		return (1);
	if (ret > 1)
	{

		maps->ctrl_line = ret;
	}

	if (check_map_validations_texture(maps))
		return (1);

	if (check_map_validations_ceilling(maps) == 1)
		return (1);

	if (check_map_validations_mapxy(maps))
		return (1);

	return (0);
}
