/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:29:36 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/06 21:34:58by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_player(t_game	*game)
{
	// inicializando com valores de teste;
	game->player.map_x = 0;
	game->player.map_y = 0;
	game->player.pos_x = game->player.column + 0.5;
	game->player.pos_y = game->player.line + 0.5;
	game->player.dir_x = 1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.666;
	game->fps.time = 0;
	game->fps.old_time = 0;
	game->player.move_speed = 0.3;
	game->player.rot_speed = M_PI / 32;
	game->texture.ceiling = game->map.ceiling; // kkkk consertar isso dps
	game->texture.floor = game->map.floor;
}

int	get_addr_locale(t_data img, int x, int y)
{
	return (y * img.line_length + x * (img.bits_per_pixel / 8));
}

unsigned int	get_pixel_color(t_data	img, int x, int y)
{
	char	*dest;

	dest = img.addr + get_addr_locale(img, x, y);
	return (*(unsigned int*)dest);
}

void	load_texture(t_game *game, t_data *texture, char *texture_path)
{
 	texture->img = mlx_xpm_file_to_image(game->mlx,
									texture_path,
									&texture->sprite_width,
									&texture->sprite_height);
	if (texture->img == NULL)
	{
		printf("error\n"); // tiraar issso
		exit(0);
	}
 	texture->addr = mlx_get_data_addr(texture->img,
									&texture->bits_per_pixel,
									&texture->line_length,
									&texture->endian);
}

void	view_direction(t_game *game)
{
	if (game->player.start_pos == 'N')
		raycasting(game);
	else if (game->player.start_pos == 'S')
		rotate_camera(game, M_PI, DIR_RIGHT);
	else if (game->player.start_pos == 'E')
		rotate_camera(game, M_PI / 2, DIR_RIGHT);
	else if (game->player.start_pos == 'W')
		rotate_camera(game, M_PI / 2, DIR_LEFT);
}

void initialize_graphics(t_game *game)
{
	init_player(game);
	load_texture(game, &game->texture.north, "./src/textures/akali.xpm"); // esse caminho já deve estar setado do .cub
	load_texture(game, &game->texture.south, "./src/textures/project_kat.xpm");
	load_texture(game, &game->texture.east, "./src/textures/katarina.xpm");
	load_texture(game, &game->texture.west, "./src/textures/kat_battle_queen.xpm");

	// first raycasting
	view_direction(game);

}
