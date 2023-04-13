#include "../../header/cub3d.h"

void get_max_col(t_map *maps)
{
	int i;

	i = 0;
	maps->max_col = 0;
	while(maps->map[i])
	{
		if (maps->max_col < ft_strlen(maps->map[i]))
			maps->max_col = ft_strlen(maps->map[i]);
		i++;
	}
}

char* my_realloc(char* str, size_t new_size)
{
	size_t old_size;

	old_size = ft_strlen(str) + 1;
	if (new_size == 0)
	{
		free(str);
		return NULL;
	}
	char* new_str = ft_calloc(sizeof(char), new_size + 1);
	if (!new_str)
		return NULL;
	if (str)
	{
		if (old_size < new_size)
			ft_memcpy(new_str, str, old_size);
	}
	free(str);
	return (new_str);
}
