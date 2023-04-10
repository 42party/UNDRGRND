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
int		check_map_path_texture(char *map, int flag);
int		check_map_floor_ceilling(char *map, int flag);
int		check_map_validations(t_map *maps);
int		get_line_map(t_map *maps, char *map_file);
int		get_info_map(t_map *maps, char *map_file);
int		check_map_x_y(t_map *maps);
int		verify_content(t_map *maps, int flag);

#endif


/*         1111111111111111111111111
        1000000000110000000000001
       11110000011100000000100001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111 */
