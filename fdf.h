/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:14:17 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/04 14:12:44 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# ifndef WIN_X
#  define WIN_X	1080
# endif

# ifndef WIN_Y
#  define WIN_Y	720
# endif

struct s_coord
{
	double	x;
	double	y;
	double	z;
	int		color;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_rot
{
	int	xb;
	int	yb;
	int	xe;
	int	ye;
};

struct s_data
{
	struct s_coord	**xy;
	int				lx;
	int				ly;
	int				x;
	int				y;
	int				scale;
	char			**sep_line;
	char			**sep_color;
	void			*mlx;
	void			*win;
	struct s_img	img;
	struct s_rot	axis;
	int				movex;
	int				movey;
};

struct s_bres
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	color;
};

char	*get_next_line(int fd);

void	ft_init_s_data(struct s_data *area);

void	ft_calc(struct s_data *area);

void	ft_center(struct s_data *area);

void	ft_iso(struct s_data *area);

int		ft_next_point(struct s_data *area);

void	ft_zoom(struct s_data *area, double faktor);

void	ft_rz(struct s_data *area, double deg);

void	ft_ry(struct s_data *area, double deg);

void	ft_rx(struct s_data *area, double deg);

void	ft_pixel_to_img(struct s_data *area);

void	ft_pixel_to_img(struct s_data *area);

void	ft_put_img(struct s_data *area);

void	ft_put_pixel(struct s_img *img, struct s_data *area);

int		ft_free_all_esc(int keycode, struct s_data *area);

int		ft_check_in(char *file);

#endif