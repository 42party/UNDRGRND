/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgorki <rgorki@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:07:41 by vipereir          #+#    #+#             */
/*   Updated: 2023/04/01 13:00:49 by rgorki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*s;

	s = NULL;
	while (lst != NULL)
	{
		nlist = ft_lstnew(((*f)(lst->content)));
		if (nlist == NULL)
		{
			ft_lstclear(&s, (*del));
			return (NULL);
		}
		ft_lstadd_back(&s, nlist);
		lst = lst->next;
	}
	return (s);
}
