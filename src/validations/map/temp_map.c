/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:57:00 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/11 15:04:14 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int get_line_map(t_map *maps, char *map_file)
{
	int fd;
	char *temp_map_line;

	maps->lines = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ret_value(1, "File does not exist"));
	temp_map_line = get_next_line(fd);
	maps->lines++;
	while(temp_map_line)
	{
		free(temp_map_line);
		temp_map_line = get_next_line(fd);
		maps->lines++;
	}
	free(temp_map_line);
	close(fd);
	if (maps->lines < 11)
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

	if(!(maps->map = ft_calloc(sizeof(char *), maps->lines + 1)))
		return (1);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (ret_value(1, "File does not exist"));
	i = 0;
	temp_map_line = get_next_line(fd);
	maps->map[i++] = ft_strdup(remove_breakline(temp_map_line));
	while(temp_map_line)
	{
		free(temp_map_line);
		temp_map_line = get_next_line(fd);
		if (temp_map_line)
			maps->map[i++] = ft_strdup(remove_breakline(temp_map_line));
	}
	free(temp_map_line);
	close(fd);
	return (0);
}

static int get_bigger_line(t_map *maps)
{
	size_t big_line;
	int i;

	i = 0;
	big_line = 0;
	while(maps->map[i])
	{
		if (big_line < ft_strlen(maps->map[i]))
			big_line = ft_strlen(maps->map[i]);
		i++;
	}
	return (big_line);
}

static char *fill_space(char *str, int big_line)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	while(len < big_line)
	{
		str[i] = 32;
		i++;
		len++;
	}
	str[i] = '\0';
	return (str);
}

int clone_map(t_map *maps)
{
	size_t big_line;
	int i;

	i = 0;
	big_line = get_bigger_line(maps);
	while(maps->map[i])
	{
		if (big_line < ft_strlen(maps->map[i]))
			maps->temp_map[i] = ft_strjoin(maps->map[i], fill_space(maps->map[i], big_line));
		else
			maps->temp_map[i] = ft_strdup(maps->map[i]);
		i++;
	}
	return (0);
}

// static int proliferation(t_map *maps)
// {

// }
