/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_validations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:37:07 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/19 13:37:53 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int	argc_verify(int argc)
{
	if (argc != 2)
	{
		printf("Invalid map or format\n");
		printf("example: ./cub3D src/maps/mapname.cub\n");
		printf("using default map instead\n");
		return (1);
		//exit(1);
	}
	return (0);
}
