/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 09:55:49 by shackbei          #+#    #+#             */
/*   Updated: 2021/08/26 09:34:55 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

size_t	ft_strlen(const char *c)
{
	size_t	counter;

	counter = 0;
	while (c[counter] != '\0')
		counter++ ;
	return (counter);
}
