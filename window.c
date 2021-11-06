/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:41:01 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/04 11:32:26 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_free_all(struct s_data *area)
{
	while (area->lx > 0)
	{
		area->lx--;
		free(area->xy[area->lx]);
	}
	free(area->xy);
	mlx_destroy_window(area->mlx, area->win);
	exit(EXIT_SUCCESS);
}

int	ft_inden(int	key, int x, int y, struct s_data *area)
{
	if (key == 5)
		ft_zoom(area, 1.5);
	else if (key == 4)
		ft_zoom(area, 0.8);
	else if (key == 1)
	{
		area->axis.xb = x;
		area->axis.yb = y;
	}
	else if (key == 3)
	{
		area->axis.xe = x;
		area->axis.ye = y;
	}
	return (0);
}

int	ft_rot(int x, int y, struct s_data *area)
{
	if (area->axis.xb > 0)
	{
		ft_rx(area, (area->axis.yb - y) * (M_PI / WIN_Y));
		ft_rz(area, (x - area->axis.xb) * (M_PI / WIN_X));
		ft_ry(area, (-x + area->axis.xb) * (M_PI / WIN_X));
		ft_pixel_to_img(area);
		area->axis.yb = y;
		area->axis.xb = x;
	}
	if (area->axis.xe > 0)
	{
		area->movex += -area->axis.xe + x;
		area->movey += -area->axis.ye + y;
		ft_pixel_to_img(area);
		area->axis.xe = x;
		area->axis.ye = y;
	}
	return (1);
}

int	ft_stop(int	key, int x, int y, struct s_data *area)
{
	area->axis.xb = 0;
	area->axis.xe = 0;
	(void)x;
	(void)y;
	(void)key;
	return (1);
}

void	ft_put_img(struct s_data *area)
{
	area->mlx = mlx_init();
	area->win = mlx_new_window(area->mlx, WIN_X, WIN_Y, "fdf");
	ft_pixel_to_img(area);
	area->axis.xb = 0;
	area->axis.xe = 0;
	mlx_hook(area->win, 17, 0, ft_free_all, area);
	mlx_hook(area->win, 04, 0, ft_inden, area);
	mlx_hook(area->win, 05, 0, ft_stop, area);
	mlx_hook(area->win, 06, 0, ft_rot, area);
	mlx_key_hook(area->win, ft_free_all_esc, area);
	mlx_loop(area->mlx);
}
