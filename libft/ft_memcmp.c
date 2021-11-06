/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:31:25 by shackbei          #+#    #+#             */
/*   Updated: 2021/08/20 09:24:41 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*ss1;
	char			*ss2;

	ss1 = (char *) s1;
	ss2 = (char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n && ss2[i] == ss1[i])
	{
		i++;
	}
	return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
}
