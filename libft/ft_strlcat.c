/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:23:08 by shackbei          #+#    #+#             */
/*   Updated: 2021/08/28 10:25:04 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (lsrc);
	if (dstsize < ldst)
		return (lsrc + dstsize);
	else
	{
		while ((ldst + i) < dstsize && src[i] != '\0')
		{
			dst[ldst + i] = src[i];
			i++;
		}
		if (ldst < dstsize && ldst + i == dstsize)
			dst[ldst + i - 1] = '\0';
		else
			dst[ldst + i] = '\0';
		return (lsrc + ldst);
	}
}
