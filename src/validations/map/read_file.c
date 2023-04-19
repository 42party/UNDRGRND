/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:17:42 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/19 14:17:59 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	get_line_map(t_map *maps, char *map_file)
{
	int		fd;
	char	*temp_map_line;

	maps->max_line = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ret_value(1, "File does not exist"));
	temp_map_line = get_next_line(fd);
	maps->max_line++;
	while (temp_map_line)
	{
		free(temp_map_line);
		temp_map_line = get_next_line(fd);
		maps->max_line++;
	}
	free(temp_map_line);
	close(fd);
	if (maps->max_line < 11)
		return (1);
	return (0);
}

char	*remove_breakline(char *str)
{
	int	i;
	int	len;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] && str[i] == '\n' && len > 1)
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
	return (str);
}

int	get_info_map(t_map *maps, char *map_file)
{
	int		fd;
	int		i;
	char	*temp_map_line;

	maps->filecub = ft_calloc(sizeof(char *), maps->max_line + 1);
	if (!maps->filecub)
		return (1);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ret_value(1, "File does not exist"));
	i = 0;
	temp_map_line = get_next_line(fd);
	maps->filecub[i++] = ft_strdup(remove_breakline(temp_map_line));
	while (temp_map_line)
	{
		free(temp_map_line);
		temp_map_line = get_next_line(fd);
		if (temp_map_line)
			maps->filecub[i++] = ft_strdup(remove_breakline(temp_map_line));
	}
	free(temp_map_line);
	close(fd);
	return (0);
}
