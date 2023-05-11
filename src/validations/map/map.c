/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:01:31 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/11 08:53:56 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	check_map_validations_texture(t_map *maps)
{
	char	**split_line;
	int		i;
//	int		fd;

	i = 0;
	while (maps->textures[i])
	{
		split_line = ft_split(maps->textures[i], 32);
		/* fd = open(split_line[1], O_RDONLY);
		if (fd == -1)
		{
			close(fd);
			printf("Error\n%s: File does not exist\n", split_line[1]);
			free_matrix(split_line);
			return (1);
		}
		else
		{
			free(split_line);
			close(fd);
		} */
		free_matrix(split_line);
		i++;
	}

	return (0);
}

int	check_map_validations_ceilling(t_map *maps)
{
	int	i;

	i = 0;
	while (maps->floor_ceilling[i])
		if (check_map_floor_ceilling(maps, maps->floor_ceilling[i++]))
			return (1);
	return (0);
}

static int	check_map_breakline(t_map *maps)
{
	int	i;

	i = 0;
	if (maps->ctrl_line == maps->max_line)
		return (ret_value(1, "Maybe you need insert a valid map"));
	maps->size_map = maps->max_line - maps->ctrl_line;
	if (maps->size_map < 4)
		return (ret_value(1, "For a minimap valid is size 4x3"));
	maps->map = ft_calloc(sizeof(char *), maps->size_map);
	if (!maps->map)
		return (1);
	while (maps->filecub[maps->ctrl_line])
	{
		if (maps->filecub[maps->ctrl_line]
			&& (my_strncmp(maps->filecub[maps->ctrl_line], "\n")))
			return (ret_value(1, "Cannot put a breakline inside map"));
		else
			maps->map[i++] = ft_strdup(maps->filecub[maps->ctrl_line++]);
	}
	return (0);
}

int	check_map_validations_mapxy(t_map *maps)
{
	int	flag;

	flag = 1;
	while (maps->filecub[maps->ctrl_line]
		&& my_strncmp(maps->filecub[maps->ctrl_line], "\n"))
			maps->ctrl_line++;
	if (check_map_breakline(maps))
		return (1);
	flag = verify_content(maps, flag);
	if (flag != 0)
		return (1);
	get_max_col(maps);
	clone_map(maps);
	if (check_map_x_y(maps))
	{
		free_matrix(maps->temp_map);
		return (1);
	}
	return (0);
}
