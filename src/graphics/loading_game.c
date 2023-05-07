/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:29:36 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/06 21:17:49 by vipereir         ###   ########.fr       */
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

void	load_textures(t_game *game)
{
	game->texture_conf.path_N_texture = "./src/textures/Marshmallow.xpm"; // isso deveria se feito antes,  qnd cata do mapa vai pegar esse path, ou via ficar o padão nosso
 	game->texture.north_texture.img = mlx_xpm_file_to_image(game->mlx,
									game->texture_conf.path_N_texture,
									&game->texture.north_texture.sprite_width,
									&game->texture.north_texture.sprite_height);
	if (game->texture.north_texture.img == NULL)
	{
		printf("error\n");
		exit(0);
	}
 	game->texture.north_texture.addr = mlx_get_data_addr(game->texture.north_texture.img,
									&game->texture.north_texture.bits_per_pixel,
									&game->texture.north_texture.line_length,
									&game->texture.north_texture.endian);

//	char *dest = game->texture.north_texture.addr + get_addr_locale(game->texture.north_texture, 2, 2);
	printf("color: %x\n", get_pixel_color(game->texture.north_texture, 2, 2));
}

void initialize_graphics(t_game *game)
{
	init_player(game);
	load_textures(game);


	// first raycasting
	raycasting(game);
}


//	paint_floor(maps, game);
//	pait_square(maps, game);