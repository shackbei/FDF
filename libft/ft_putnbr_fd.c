/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 14:17:26 by shackbei          #+#    #+#             */
/*   Updated: 2021/09/11 14:17:26 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static long	ft_print(long c, int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (0);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		c = c * -1;
	}
	return (c);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		a;
	long	c;
	long	b;

	a = 0;
	b = 10000000000;
	c = n;
	if (n <= 0)
		c = ft_print (c, n, fd);
	if (c == 0)
		return ;
	while (b != 0)
	{
		while (c / b == 0)
			b = b / 10;
		while (b > 0)
		{
			a = c / b;
			c = c - (a * b);
			a = a + 48;
			write(fd, &a, 1);
			b = b / 10;
		}
	}
}
