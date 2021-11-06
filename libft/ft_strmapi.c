/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:14:36 by shackbei          #+#    #+#             */
/*   Updated: 2021/09/04 17:14:36 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*a;
	unsigned int	i;

	i = 0;
	if (s == 0 || f == 0)
		return (0);
	a = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (a == 0 || s == 0 || f == 0)
		return (0);
	while (s[i] != 0)
	{
		a[i] = f(i, s[i]);
		i++;
	}
	return (a);
}
