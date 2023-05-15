/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separete_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 06:41:55 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/15 06:42:46 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	aux_loop_texture(t_map *maps, char *split_0, char *split_1)
{
	if (my_strncmp("EA", split_0))
	{
		if (!maps->textures[3])
			maps->textures[3] = ft_strjoin("EA ", split_1);
		maps->count_texture++;
		maps->flag += 1;
	}
}
