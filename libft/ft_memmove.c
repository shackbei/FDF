/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:58:53 by shackbei          #+#    #+#             */
/*   Updated: 2021/08/26 09:32:34 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*surc;
	int			i;

	dest = (char *)dst;
	surc = (char *)src;
	i = 0;
	if (dest > surc)
	{
		while (len > 0)
		{
			len--;
			dest[len] = surc[len];
		}
	}
	if (dest < surc)
	{
		while (len > 0)
		{
			len--;
			dest[i] = surc[i];
			i++;
		}
	}
	return (dst);
}
