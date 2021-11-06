/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 09:33:27 by shackbei          #+#    #+#             */
/*   Updated: 2021/08/26 09:06:58 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = 0;
	while (lst != 0)
	{
		if (lst->content != 0)
		{
			tmp = ft_lstnew(f(lst->content));
			ft_lstadd_back(&new, tmp);
		}
		else
			ft_lstclear(&new, del);
		lst = lst->next;
	}
	return (new);
}
