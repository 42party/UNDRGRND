#include "../../header/cub3d.h"

static int	check_map_path_texture_utils(char *temp_map_line, int flag)
{
	char	**split_line;
	size_t	size;

	split_line = ft_split(temp_map_line, 32);
	size = array_counter(split_line);
	if (!split_line || size != 2)
	{
		free(split_line);
		return (ret_value(1, "Format incompatible: direction more path texture"));
	}
	if (my_strncmp("NO", split_line[0]))
		if (my_strncmp("../textures/north\n", split_line[1]))
			flag += 8;
	if (my_strncmp("SO", split_line[0]))
		if (my_strncmp("../textures/south\n", split_line[1]))
			flag += 4;
	if (my_strncmp("WE", split_line[0]))
		if (my_strncmp("../textures/west\n", split_line[1]))
			flag += 2;
	if (my_strncmp("EA", split_line[0]))
		if (my_strncmp("../textures/east\n", split_line[1]))
			flag += 1;
	free_matrix(split_line);
	return (flag);
}

int	check_map_path_texture(int fd, int flag)
{
	char	*temp_map_line;

	temp_map_line = get_next_line(fd);
	flag = check_map_path_texture_utils(temp_map_line, flag);
	free(temp_map_line);
	return (flag);
}
