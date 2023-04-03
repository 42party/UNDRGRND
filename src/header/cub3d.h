#ifndef CUB3D_H
# define CUB3D_H

#include "../libs/libft/libft.h"
#include "../libs/mlx/mlx.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

/* # define NO	1
# define SO	2
# define EO	3
# define WO	4

# define NO ./path_to_the_north_texture
# define SO ./path_to_the_south_texture
# define WE ./path_to_the_west_texture
# define EA ./path_to_the_east_texture */

typedef struct	s_map
{
	char	**map;
	int		lines;
	int		has_direction;
	int		has_textures;
	int		has_floor;
	int		has_ceilling;
}				t_map;

//utils
int		my_atoi(const char *str);
int		my_strncmp(const char *s1, const char *s2);
int		ret_value(int i, char *msg);
int		create_trgb(int t, int r, int g, int b);
int		array_counter(char **arr);
int		free_matrix(char **matrix);
char	**matrix_dup(char **mat);
//validations


//validations-map
int		check_map_extension(char *map_name);
int		check_map_path_texture(int fd, int flag);
int		check_map_floor_ceilling(int fd, int flag);
int		check_map_validations(char *map_file);
int		get_info_maps(t_map *map, char *map_file);

#endif
