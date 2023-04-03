/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:47:40 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/03 12:57:40 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*s1)
{
	char	*string;
	size_t	i;

	i = 0;
	string = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (string == NULL)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

/*
#include <stdio.h>

int	main (void)
{
	char	*str = "cópia, copy, kopi";
	printf("%s\n", ft_strdup(str));
	return (0);
}*/
