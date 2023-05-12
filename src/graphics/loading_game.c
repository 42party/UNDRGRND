/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:29:36 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/12 10:14:04 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_player(t_game	*game)
{
	game->player.map_x = 0;
	game->player.map_y = 0;
	game->player.pos_x = game->player.column + 0.5;
	game->player.pos_y = game->player.line + 0.5;
	game->player.dir_x = 1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.666;
	game->player.move_speed = 0.3;
	game->player.rot_speed = M_PI / 32;
	game->texture.ceiling = game->map.ceiling;
	game->texture.floor = game->map.floor;
}

void	load_texture(t_game *game, t_data *texture, char *texture_path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx,
			texture_path,
			&texture->sprite_width,
			&texture->sprite_height);
	if (texture->img == NULL)
	{
		printf("error mlx\n");
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

void	initialize_graphics(t_game *game)
{
	init_player(game);
	load_texture(game, &game->texture.north, game->map.textures[0]);
	load_texture(game, &game->texture.south, game->map.textures[1]);
	load_texture(game, &game->texture.east, game->map.textures[2]);
	load_texture(game, &game->texture.west, game->map.textures[3]);
	view_direction(game);
}
