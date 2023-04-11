/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:47:20 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/03 12:43:56 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*vp;

	if (size == 0 || count == 0)
	{
		count = 1;
		size = 1;
	}
	vp = malloc(count * size);
	if (vp == NULL)
		return (NULL);
	ft_bzero(vp, count * size);
	return (vp);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*array;
	int	i;

	i = 0;
	array = (char *)ft_calloc(2, 2);
	while (i < 22)
	{
		if (array[i] == 0)
			printf("\\0");
		else
			printf("%c", array[i]);
		i++;
	}
	printf("\n");
	return(0);
}*/
