/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:52:27 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/06 14:14:40 by vipereir         ###   ########.fr       */
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

# define DISPLAY_HEIGHT 800
# define DISPLAY_WIDTH 800

# ifdef __linux__

enum {
	CLICK_X = 17,
	KEY_ESC = 65307,
	KEY_UP = 119,
	KEY_LEFT = 97,
	KEY_DOWN = 115,
	KEY_RIGHT = 100,
	CAM_ARROW_RIGHT = 65363,
	CAM_ARROW_LEFT = 65361
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
	FLOOR = '0',
	SIDE_X = 0,
	SIDE_Y = 0,
};

typedef struct s_color {
	int	red;
	int	green;
	int	blue;
}				t_color;
typedef struct s_map {
	char	**filecub;
	char	**map;
	char	**map_square;
	char	**temp_map;
	int		tmp_max_line;
	int		tmp_max_col;
	int		ctrl_line;
	int		max_line;
	int		size_map;
	size_t	max_col;
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

# define FOV 60

typedef struct s_player
{
	char	start_pos;
	int		line;
	int		column;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	int		mapX;
	int		mapY;
	double	planeX;
	double	planeY;
	double	moveSpeed;
	double	rotSpeed;
}				t_player;

typedef struct s_fps {
	double	time;
	double	old_time;
} t_fps;


typedef struct s_texture {
	void	*north_texture;
	char	*north_path;
	void	*south_texture;
	char	*south_path;
	void	*east_texture;
	char	*east_path;
	void	*west_texture;
	char	*west_path;
	
} t_texture;


typedef struct s_game {
	void		*mlx;
	void		*win;
	t_data		img; // renomerar para layner // layer do 3d
	t_data		minimap_layer;
	t_map		map;
	t_player	player;
	t_fps		fps;
}	t_game;

// graphics
void	initialize_graphics(t_map *maps, t_game *game);
void	pait_square(t_map *maps, t_game *game);

//utils
int		my_atoi(const char *str);
int		my_strncmp(const char *s1, const char *s2);
int		ret_value(int i, char *msg);
int		create_trgb(int t, int r, int g, int b);
int		array_counter(char **arr);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
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
int		radar_validation(t_map *maps);
int		validations(t_map *maps, char **argv);
void	get_max_col(t_map *maps);
void	square_map(t_map *maps);
char	*my_realloc(char *str, size_t new_size);

//player
void	get_player_position(t_map *maps, t_player *player);
int		move_player(t_game *game, t_player *players, t_map *maps, int keycode);
void	square(t_game *game, int color);

// player movement and camera view

int		get_key(int keycode, t_game *game);
void    move_forward(t_game *game);
void    move_backward(t_game *game);
void    move_left(t_game *game);
void    move_right(t_game *game);
void    rotate_camera_left(t_game *game);
void    rotate_camera_right(t_game *game);

// window management
void	load_game(t_game *game);
void	init_game(t_game *game);
int		raycasting(t_game *game);
void    draw_vertical_line(int  display_X, int draw_start,
            int draw_end, int color, t_game *game);


// exit functions
int		close_game(t_game *game);

#endif
