/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:07:02 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/01 13:00:51 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	p = *lst;
	while (*lst != NULL)
	{
		p = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = p;
	}
	*lst = NULL;
}
