/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:52:27 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/09 15:09:02 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# ifdef __linux__ //linux keymaps

enum {
	KEY_ESC = 65307,
	// movement based on WASD standard
	KEY_UP = 119,	// W
	KEY_LEFT = 97,	// A
	KEY_DOWN = 115,	// S
	KEY_RIGHT = 100	// D
};

# elif defined(__APPLE__) // mac keymaps

enum {   //verificar os valores no mac
	KEY_ESC = 53,
	// movement based on WASD standard
	KEY_UP = 13,	// W
	KEY_LEFT = 0,	// A
	KEY_DOWN = 1,	// S
	KEY_RIGHT = 2	// D
};

# endif

/* # define NO	1
# define SO	2
# define EO	3
# define WO	4

# define NO ./path_to_the_north_texture
# define SO ./path_to_the_south_texture
# define WE ./path_to_the_west_texture
# define EA ./path_to_the_east_texture */


//type defs && structs

typedef struct	s_map
{
	char	**map;
	int		has_direction;
	int		has_textures;
	int		has_floor;
	int		has_ceilling;
}				t_map;


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

// exit functions

void	close_game(t_window *win);

#endif
