/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:52:27 by vipereir          #+#    #+#             */
/*   Updated: 2023/05/10 14:09:47 by vipereir         ###   ########.fr       */
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
	KEY_RIGHT = 2,
	CAM_ARROW_RIGHT = 124,
	CAM_ARROW_LEFT = 123
};

# endif

enum {
	PLAYER = 'P',
	WALL = '1',
	FLOOR = '0',
	SIDE_X = 0,
	SIDE_Y = 1,
};

typedef struct s_vars {
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit_wall; // n precisa
	int		hit_side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	tex_step;
	double	tex_pos;
}				t_vars;

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
	char	**textures;
	char	**floor_ceilling;
	int		flag;
	int		count_fc;
	int		count_texture;
	int		tmp_max_line;
	int		tmp_max_col;
	int		ctrl_line;
	int		max_line;
	int		size_map;
	size_t	max_col;
	t_color	ceiling; // mudar isso para a t_texture;
	t_color	floor;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	// for texture only usage
	int		sprite_width;
	int		sprite_height;
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
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}				t_player;

typedef struct s_fps {
	double	time;
	double	old_time;
} t_fps;


typedef struct s_texture {
	t_data	north;
	t_data	south;
	t_data	east;
	t_data	west;
	t_color	ceiling;
	t_color	floor;
} t_texture;


typedef struct s_config {
	char	*path_N_texture;
	char	*path_S_texture;
	char	*path_E_texture;
	char	*path_W_texture;
} t_config;


typedef struct s_game {
	void		*mlx;
	void		*win;
	t_data		img; // renomerar para layner // layer do 3d
	t_data		minimap_layer;
	t_map		map;
	t_player	player;
	t_fps		fps;
	t_texture	texture;
	t_config	texture_conf;
}	t_game;

// graphics
void initialize_graphics(t_game *game);
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
int		check_map_path_texture(t_map *maps, char *map);
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
int		separete_cub(t_map *maps);
void	get_max_col(t_map *maps);
void	square_map(t_map *maps);
char	**ft_split_mod(char const *s);
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
unsigned int	get_pixel_color(t_data	img, int x, int y);
int		get_addr_locale(t_data img, int x, int y);
void	load_game(t_game *game);
void	init_game(t_game *game);
int		raycasting(t_game *game);
void    draw_vertical_line(int  display_X, int draw_start,
            int draw_end, int color, t_game *game);
void    draw_texturized_vertical_line(t_game *game, t_vars *vars, int display_x);


// exit functions
int		close_game(t_game *game);

#endif
