/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:22:11 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/04 10:38:09 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_next_point(struct s_data *area)
{
	if (area->x < area->lx)
		area->x++;
	if (area->x == area->lx)
	{
		area->x = 0;
		area->y++;
	}
	if (area->y < area->ly)
	{
		return (1);
	}
	return (0);
}

void	ft_iso(struct s_data *area)
{
	ft_rx(area, M_PI / 6);
	ft_ry(area, M_PI / 6);
	ft_rz(area, -M_PI / 6);
}

void	ft_center(struct s_data *area)
{
	area->x = 0;
	area->y = 0;
	while (area->y < area->ly)
	{
		while (area->x < area->lx)
		{
			area->xy[area->x][area->y].x
				 = (area->x - (area->lx / 2)) * area->scale;
			area->xy[area->x][area->y].y
				 = (-area->y + (area->ly / 2)) * area->scale;
			area->x++;
		}
		area->x = 0;
		area->y++;
	}
}

void	ft_calc(struct s_data *area)
{
	int	ret;

	ret = WIN_X / (sqrt((pow(area->ly, 2) + pow(area->lx, 2))));
	area->scale = ret;
}

void	ft_init_s_data(struct s_data *area)
{
	area->sep_line = NULL;
	area->lx = 0;
	area->ly = 0;
	area->x = 0;
	area->y = 0;
	area->movex = 0;
	area->movey = 0;
	area->xy = NULL;
}
