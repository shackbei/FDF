/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 09:50:31 by shackbei          #+#    #+#             */
/*   Updated: 2021/08/20 11:05:20 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	l;

	l = ft_strlen(s1) + 1;
	a = malloc(l);
	if (a == 0)
		return (NULL);
	a = ft_memcpy(a, s1, l);
	return (a);
}
