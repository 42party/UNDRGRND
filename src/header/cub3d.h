/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:52:27 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/25 15:33:21 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

// config defines

# define DISPLAY_HEIGHT 400
# define DISPLAY_WIDTH 600

# ifdef __linux__

enum {
	CLICK_X = 17,
	KEY_ESC = 65307,
	KEY_UP = 119,
	KEY_LEFT = 97,
	KEY_DOWN = 115,
	KEY_RIGHT = 100
};

# elif defined(__APPLE__)

enum {
	CLICK_X = 17,
	KEY_ESC = 53,
	KEY_UP = 13,
	KEY_LEFT = 0,
	KEY_DOWN = 1,
	KEY_RIGHT = 2
};

# endif

enum {
	PLAYER = 'P',
	WALL = '1',
	FLOOR = '0'
};

typedef struct s_color {
	int	red;
	int	green;
	int	blue;
}				t_color;
typedef struct s_map {
	char	**filecub;
	char	**map;
	int		ctrl_line;
	int		max_line;
	size_t	max_col;
	int		size_map;
	char	**temp_map;
	int		tmp_max_line;
	int		tmp_max_col;
	t_color	ceiling;
	t_color	floor;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_position{
	int	x;
	int	y;
}				t_position;

# define POV 60

typedef struct s_player{
	t_position	position_on_plane;
	t_position	position_on_map;
	int			view_direction;
}				t_player;

typedef struct s_window {
	void		*mlx;
	void		*win;
	t_data		img;
	t_map		map;
	t_player	player;
}	t_window;

// graphics
void	initialize_graphics(t_map *maps, t_window *win);
void	paint_floor(t_map *maps, t_window *win);

//utils
int		my_atoi(const char *str);
int		my_strncmp(const char *s1, const char *s2);
int		ret_value(int i, char *msg);
int		create_trgb(int t, int r, int g, int b);
int		array_counter(char **arr);
void	my_mlx_pixel_put(t_window *win, int x, int y, int color);
int		free_matrix(char **matrix);
char	**matrix_dup(char **mat);
void	free_maps(t_map *maps);

//validations-main
void	argc_verify(int argc);

//validations-map
int		check_map_extension(char *map_name);
int		check_map_path_texture(char *map, int flag);
int		check_map_floor_ceilling(t_map *maps, char *map, int flag);
int		check_map_validations(t_map *maps);
int		check_map_validations_texture(t_map *maps);
int		check_map_validations_ceilling(t_map *maps);
int		check_map_validations_mapxy(t_map *maps);
int		get_line_map(t_map *maps, char *map_file);
int		get_info_map(t_map *maps, char *map_file);
int		check_map_x_y(t_map *maps);
int		verify_content(t_map *maps, int flag);
int		clone_map(t_map *maps);
void	get_max_col(t_map *maps);
char	*my_realloc(char *str, size_t new_size);
int		radar_validation(t_map *maps);
int		validations(t_map *maps, char **argv);

//player
void	get_player_possition(char **map, int lines);

// window management
void	load_game(t_window *win);
void	init_window(t_window *win);

// exit functions
int		close_game(t_window *win);

#endif
