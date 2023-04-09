#ifndef CUB3D_H
# define CUB3D_H

#include "../libs/libft/libft.h"
#include "../libs/mlx/mlx.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>

// config defines

# define DISPLAY_HEIGHT 400
# define DISPLAY_WIDTH 600

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

//player

typedef struct s_possition{
	int	x;
	int y;
} 			t_possition;

# define POV 60

typedef struct s_player{
	t_possition possition_on_plane;
	t_possition possition_on_map;
	int 		view_direction; // 0 - 360
}			t_player;

// mlx funcs

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_window {
	void	*mlx;
	void	*win;
	t_data	img;


}t_window;


# ifndef __linux__ //linux keymaps

enum {
	KEY_UP = 0x67; //103
};

# elif defined(__APPLE__) // mac keymaps

enum {
	KEY_UP = 0x67; //103
};
# endif


#endif
