/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki < rgorki@student.42.rio>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:38:06 by rgorki            #+#    #+#             */
/*   Updated: 2023/04/19 13:53:01 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	my_strncmp(const char *s1, const char *s2)
{
	int		i;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (0);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 != len_s2)
		return (0);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	my_atoi(const char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	if (!str)
	{
		res = 424242;
		return (res);
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			res = 424242;
			break ;
		}
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}
