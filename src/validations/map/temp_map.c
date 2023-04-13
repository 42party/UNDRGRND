/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:57:00 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/13 14:48:32 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int get_line_map(t_map *maps, char *map_file)
{
	int fd;
	char *temp_map_line;

	maps->max_line = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ret_value(1, "File does not exist"));
	temp_map_line = get_next_line(fd);
	maps->max_line++;
	while(temp_map_line)
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

char *remove_breakline(char *str)
{
	int i;
	int len;

	if (!str)
		return (NULL);
	i = 0;
	len = ft_strlen(str);
	while(str[i])
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
int get_info_map(t_map *maps, char *map_file)
{
	int fd;
	int i;
	char *temp_map_line;

	if(!(maps->filecub = ft_calloc(sizeof(char *), maps->max_line + 1)))
		return (1);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ret_value(1, "File does not exist"));
	i = 0;
	temp_map_line = get_next_line(fd);
	maps->filecub[i++] = ft_strdup(remove_breakline(temp_map_line));
	while(temp_map_line)
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

static char *fill_space(char *str, int max_col)
{
	int		len;
	char	*temp_str;

	len = ft_strlen(str);
	temp_str = my_realloc(str, max_col);
	while (len < max_col)
		temp_str[len++] = 32;
	return (temp_str);
}

int clone_map(t_map *maps)
{
	int i;
	char *temp;

	i = 0;
	maps->temp_map = ft_calloc(sizeof(char *), maps->size_map);
	if (!maps->temp_map)
		return (1);
	while(maps->map[i])
	{
		if (maps->max_col > ft_strlen(maps->map[i]))
		{
			temp = ft_strdup(maps->map[i]);
			temp = fill_space(temp, maps->max_col);
			maps->temp_map[i] = ft_strdup(temp);
			free(temp);
		}
		else
			maps->temp_map[i] = ft_strdup(maps->map[i]);
		i++;
	}
	return (0);
}
