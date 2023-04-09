/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/09 15:04:34 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

/* static void validations(char **argv)
{
	if (check_map_validations(argv[1]))
		printf("VALIDATIONS");
} */

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_key(int keycode, t_window *win)
{
	(void)win;
	printf("keycode: %i\n", keycode);
	if (keycode == KEY_ESC)
		close_game(win);
	return (0);
}

int main(int argc, char **argv)
{
//	validations(argv);
	t_window	win;
	(void)argc;
	(void)argv;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT, "fvck!");
	win.img.img = mlx_new_image(win.mlx, DISPLAY_WIDTH, DISPLAY_HEIGHT);

//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//								&img.endian);

//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//	my_mlx_pixel_put(&img, 5, 10, 0x00FF0000);
//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//	mlx_hook();
	printf("%i\n", KEY_UP);
	mlx_key_hook(win.win, get_key, &win);
	mlx_loop(win.mlx);
	return (0);
}

