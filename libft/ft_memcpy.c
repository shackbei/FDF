/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 10:26:55 by shackbei          #+#    #+#             */
/*   Updated: 2021/08/28 10:24:49 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*surc;

	if (n == 0 || (dst == (void *)0 && src == (void *)0))
		return ((void *)dst);
	dest = (char *)dst;
	surc = (const char *)src;
	while (n > 0)
	{
		n--;
		dest[n] = surc[n];
	}
	return (dst);
}
