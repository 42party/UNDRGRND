/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:03:30 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/04 12:08:18 by vipereir         ###   ########.fr       */
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
	(void)argc;
	validations(argv);


	return (0);
}

