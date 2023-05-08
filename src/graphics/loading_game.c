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
	game->player.mapX = 0;
	game->player.mapY = 0;
	game->player.posX = game->player.column;
	game->player.posY = game->player.line;
	game->player.dirX = 1;
	game->player.dirY = 0;
	game->player.planeX = 0;
	game->player.planeY = 0.666;
	game->fps.time = 0;
	game->fps.old_time = 0;
	game->player.moveSpeed = 0.3;
	game->player.rotSpeed = 0.1;
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
		printf("error\n");
		exit(0);
	}
 	texture->addr = mlx_get_data_addr(texture->img,
									&texture->bits_per_pixel,
									&texture->line_length,
									&texture->endian);
	printf("color %x\n", get_pixel_color(*texture, 2, 2));
}

void initialize_graphics(t_game *game)
{
	init_player(game);
	load_texture(game, &game->texture.north, "./src/textures/d-evil-s.xpm"); // esse caminho já deve estar setado do .cub
	load_texture(game, &game->texture.south, "./src/textures/Marshmallow.xpm");
	load_texture(game, &game->texture.east, "./src/textures/Marshmallow.xpm");
	load_texture(game, &game->texture.west, "./src/textures/Marshmallow.xpm");

	// first raycasting
	raycasting(game);
}