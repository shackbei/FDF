/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:12:46 by shackbei          #+#    #+#             */
/*   Updated: 2021/08/26 09:30:57 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != 0 && del != 0)
	{
		del(lst->content);
		free(lst);
	}
}
