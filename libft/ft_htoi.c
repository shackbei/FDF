/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:56:12 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/03 20:03:08 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_htoi(const char *str)
{
	int		j;
	int		i;
	int		ret;
	char	*list;

	j = 0;
	ret = 0;
	list = "0123456789ABCDEF";
	i = 2;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
	{
		while (str[i])
		{
			while (str[i] != list[j] && str[i]
				 != ft_tolower(list[j]) && list[j])
			{
				j++;
			}
			if (list[j])
				ret = ret * 16 + j;
			j = 0;
			i++;
		}
	}
	return (ret);
}
