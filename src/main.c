/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/06 09:27:17 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static void validations(char **argv)
{
	if (check_map_validations(argv[1]))
		printf("VALIDATIONS");
}

int main(int argc, char **argv)
{
	void	*mlx;
	void	*img;
	(void)argc;

//	validations(argv);

	mlx = mlx_init();
	img = mlx_new_image(mlx, DISPLAY)

	

	return (0);
}

