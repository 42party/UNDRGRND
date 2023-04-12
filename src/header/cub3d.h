/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:52:27 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/12 17:11:33 by rgorki           ###   ########.fr       */
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

# define DISPLAY_HEIGHT 400  // isso tmb é colunar e linhas
# define DISPLAY_WIDTH 600

# ifdef __linux__ //linux keymaps

enum {
	CLICK_X = 17,
	KEY_ESC = 65307,
	// movement based on WASD standard
	KEY_UP = 119,	// W
	KEY_LEFT = 97,	// A
	KEY_DOWN = 115,	// S
	KEY_RIGHT = 100	// D
};

# elif defined(__APPLE__) // mac keymaps

enum {   //verificar os valores no mac
	CLICK_X = 17,
	KEY_ESC = 53,
	// movement based on WASD standard
	KEY_UP = 13,	// W
	KEY_LEFT = 0,	// A
	KEY_DOWN = 1,	// S
	KEY_RIGHT = 2	// D
};

# endif

enum {
	PLAYER = 'P',
	WALL = '1',
	FLOOR = '0'
};

/* # define NO	1
# define SO	2
# define EO	3
# define WO	4

# define NO ./path_to_the_north_texture
# define SO ./path_to_the_south_texture
# define WE ./path_to_the_west_texture
# define EA ./path_to_the_east_texture */


//type defs && structs

typedef struct	s_map {
	char	**filecub;
	char	**map;
	int		ctrl_line;
	int		max_line;
	int		max_col;
	int		size_map;
	char	**temp_map;
}				t_map;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

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




typedef struct s_window {
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	map;
	t_player  player; // to pensando em chamar de game, t_game
}	t_window;

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
int		check_map_path_texture(char *map, int flag);
int		check_map_floor_ceilling(char *map, int flag);
int		check_map_validations(t_map *maps);
int		get_line_map(t_map *maps, char *map_file);
int		get_info_map(t_map *maps, char *map_file);
int		check_map_x_y(t_map *maps);
int		verify_content(t_map *maps, int flag);
int clone_map(t_map *maps);


//player

void	get_player_possition(char **map, int lines);

// window management

void	load_game(t_window *win);
void	init_window(t_window *win);

// exit functions

int		close_game(t_window *win);

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
