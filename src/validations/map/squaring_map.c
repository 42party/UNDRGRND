/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squaring_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 08:54:27 by rgorki            #+#    #+#             */
/*   Updated: 2023/05/12 09:56:36 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static char	*fill_space(char *str, int max_col)
{
	int		len;
	char	*temp_str;

	len = ft_strlen(str);
	temp_str = my_realloc(str, max_col);
	while (len < max_col - 1)
		temp_str[len++] = 32;
	return (temp_str);
}

void	square_map(t_map *maps)
{
	int		i;
	char	*temp;

	i = 0;
	maps->map_square = ft_calloc(sizeof(char *), maps->size_map);
	if (!maps->map_square)
		exit(1);
	while (maps->map[i] && i < maps->size_map)
	{
		if (ft_strlen(maps->map[i]) == maps->max_col)
			maps->map_square[i] = ft_strdup(maps->map[i]);
		else
		{
			temp = ft_strdup(maps->map[i]);
			maps->map_square[i] = fill_space(temp, maps->max_col + 1);
		}
		i++;
	}
}
