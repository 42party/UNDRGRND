/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:44:54 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/20 09:45:06 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	check_map_extension(char *map_name)
{
	char	*extension;
	char	*temp_name;
	int		fd;

	if (!map_name)
		return (ret_value(1, "Missing map name: format namefile.cub"));
	extension = ".cub";
	temp_name = ft_strrchr(map_name, '.');
	if (!my_strncmp(temp_name, extension))
		return (ret_value(1, "Missing extension\nexample: namefile.cub"));
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (ret_value(1, "File does not exist"));
	close(fd);
	return (0);
}
