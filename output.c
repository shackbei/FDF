/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:32:24 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/04 14:13:54 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_to_img(struct s_data *area)
{
	struct s_img	img;

	img.img = mlx_new_image(area->mlx, WIN_X, WIN_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_put_pixel(&img, area);
	mlx_put_image_to_window(area->mlx, area->win, img.img, 0, 0);
	mlx_destroy_image(area->mlx, img.img);
}

void	my_mlx_pixel_put(struct s_img *data, int x, int y, int color)
{
	char	*dst;

	if (x < WIN_X && x >= 0 && y < WIN_Y && y >= 0)
	{
		dst = data->addr
			 + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_sx_sy(struct s_coord *beg, struct s_coord *end, struct s_bres *value)
{
	end->x = (int)(end->x + (WIN_X / 2));
	end->y = (int)(-end->y + (WIN_Y / 2));
	beg->x = (int)(beg->x + (WIN_X / 2));
	beg->y = (int)(-beg->y + (WIN_Y / 2));
	value->dx = fabs(end->x - beg->x);
	value->dy = -fabs(end->y - beg->y);
	value->err = value->dx + value->dy;
	if (beg->x < end->x)
		value->sx = 1;
	else
		value->sx = -1;
	if (beg->y < end->y)
		value->sy = 1;
	else
		value->sy = -1;
}

void	ft_line(struct s_coord beg, struct s_coord end,
			 struct s_img *img, struct s_data *data)
{
	struct s_bres	value;

	ft_sx_sy(&beg, &end, &value);
	while (1)
	{
		my_mlx_pixel_put(img, beg.x + data->movex,
			 beg.y + data->movey, beg.color);
		if (fabs(beg.x) == fabs(end.x) && fabs(beg.y) == fabs(end.y))
			break ;
		value.e2 = 2 * value.err;
		if (value.e2 > value.dy)
		{
			value.err += value.dy;
			beg.x += value.sx;
		}
		if (value.e2 < value.dx)
		{
			value.err += value.dx;
			beg.y += value.sy;
		}
	}
}

void	ft_put_pixel(struct s_img *img, struct s_data *area)
{
	area->x = -1;
	area->y = 0;
	while (ft_next_point(area))
	{
		if (area->x > 0)
			ft_line(area->xy[area->x - 1][area->y],
				 area->xy[area->x][area->y], img, area);
		if (area->y > 0)
			ft_line(area->xy[area->x][area->y - 1],
				 area->xy[area->x][area->y], img, area);
	}
}
