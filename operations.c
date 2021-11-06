/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:29:35 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/04 11:18:55 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_free_all_esc(int keycode, struct s_data *area)
{
	keycode = 0;
	while (area->lx > 0)
	{
		area->lx--;
		free(area->xy[area->lx]);
	}
	free(area->xy);
	mlx_destroy_window(area->mlx, area->win);
	exit(EXIT_SUCCESS);
}

void	ft_rx(struct s_data *area, double deg)
{
	area->x = -1;
	area->y = 0;
	while (ft_next_point(area))
	{
		area->xy[area->x][area->y].y = area->xy[area->x][area->y].y
			 * cos(deg) - area->xy[area->x][area->y].z * sin(deg);
		area->xy[area->x][area->y].z = area->xy[area->x][area->y].y
			 * sin(deg) + area->xy[area->x][area->y].z * cos(deg);
	}
}

void	ft_ry(struct s_data *area, double deg)
{
	area->x = -1;
	area->y = 0;
	while (ft_next_point(area))
	{
		area->xy[area->x][area->y].x = area->xy[area->x][area->y].x
			 * cos(deg) + area->xy[area->x][area->y].z * sin(deg);
		area->xy[area->x][area->y].z = -area->xy[area->x][area->y].x
			 * sin(deg) + area->xy[area->x][area->y].z * cos(deg);
	}
}

void	ft_rz(struct s_data *area, double deg)
{
	area->x = -1;
	area->y = 0;
	while (ft_next_point(area))
	{
		area->xy[area->x][area->y].x = area->xy[area->x][area->y].x
			 * cos(deg) - area->xy[area->x][area->y].y * sin(deg);
		area->xy[area->x][area->y].y = area->xy[area->x][area->y].x
			 * sin(deg) + area->xy[area->x][area->y].y * cos(deg);
	}
}

void	ft_zoom(struct s_data *area, double faktor)
{
	area->x = -1;
	area->y = 0;
	while (ft_next_point(area))
	{
		area->xy[area->x][area->y].x = area->xy[area->x][area->y].x * faktor;
		area->xy[area->x][area->y].y = area->xy[area->x][area->y].y * faktor;
		area->xy[area->x][area->y].z = area->xy[area->x][area->y].z * faktor;
	}
	ft_pixel_to_img(area);
}
