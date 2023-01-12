/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuchard <chuchard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:11:15 by chuchard          #+#    #+#             */
/*   Updated: 2022/11/11 23:57:31 by chuchard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;

	res = 0;
	if (!lst || !(*f) || !(*del))
		return (NULL);
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
			ft_lstdelone(res, (*del));
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}
