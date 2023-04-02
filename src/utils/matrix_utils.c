/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:36:29 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/02 12:36:30 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	array_counter(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**matrix_dup(char **mat)
{
	char	**dup;
	int		i;

	i = 0;
	dup = ft_calloc(sizeof(char *), array_counter(mat) + 1);
	while (mat[i])
	{
		dup[i] = ft_strdup(mat[i]);
		i++;
	}
	return (dup);
}

int	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (1);
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	return (1);
}
