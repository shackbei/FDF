/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:22:19 by shackbei          #+#    #+#             */
/*   Updated: 2021/09/04 20:21:36 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*a;

	i = 0;
	if (s == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		a = ft_calloc(1, 1);
		if (a == 0)
			return (0);
		return (a);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	a = ft_calloc(len + 1, 1);
	if (a == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		a[i] = s[start + i];
		i++;
	}
	return (a);
}
