#include "../../header/cub3d.h"

int	check_map_path_texture(char *map, int flag)
{
	char	**split_line;
	size_t	size;

	split_line = ft_split(map, 32);
	size = array_counter(split_line);
	if (!split_line || size != 2)
	{
		free(split_line);
		return (ret_value(1, "Format incompatible: direction more path texture"));
	} // verificar esse error pra ver se limpa todos os leaks
	if (my_strncmp("NO", split_line[0]))
		if (my_strncmp("../textures/north", split_line[1]))
			flag += 8;
	if (my_strncmp("SO", split_line[0]))
		if (my_strncmp("../textures/south", split_line[1]))
			flag += 4;
	if (my_strncmp("WE", split_line[0]))
		if (my_strncmp("../textures/west", split_line[1]))
			flag += 2;
	if (my_strncmp("EA", split_line[0]))
		if (my_strncmp("../textures/east", split_line[1]))
			flag += 1;
	free_matrix(split_line);
	return (flag);
}
