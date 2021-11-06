/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shackbei <shackbei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:20:05 by shackbei          #+#    #+#             */
/*   Updated: 2021/11/04 14:14:35 by shackbei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_point(struct s_data *area)
{
	area->sep_color = ft_split(area->sep_line[area->x], ',');
	area->xy[area->x][area->y].z
		= ft_atoi(area->sep_color[0]) * -area->scale / 5;
	area->xy[area->x][area->y].color
		= fabs(0x00FFFFFF - (area->xy[area->x][area->y].z * 500000));
	if (area->sep_color[1] != NULL)
		area->xy[area->x][area->y].color = ft_htoi(area->sep_color[1]);
	free(area->sep_color[0]);
	free(area->sep_color[1]);
	free(area->sep_color);
	free(area->sep_line[area->x]);
	area->x++;
}

void	ft_fill_xy(char *file, struct s_data *area)
{
	int		fd;
	char	*newl;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror(NULL);
	ft_calc(area);
	area->x = 0;
	while (area->y < area->ly || area->y == 0)
	{
		newl = get_next_line(fd);
		area->sep_line = ft_split(newl, ' ');
		free(newl);
		while (area->x < area->lx && area->sep_line[area->x])
		{
			ft_fill_point(area);
		}
		free(area->sep_line);
		area->x = 0;
		area->y++;
	}
	close(fd);
}

void	ft_malloc_xy(struct s_data *area)
{
	area->xy = (struct s_coord **)malloc(sizeof(struct s_coord *) * area->lx);
	while (area->x < area->lx)
	{
		area->xy[area->x]
			 = (struct s_coord *)malloc(sizeof(struct s_coord) * area->ly);
		area->x++;
	}
}

struct s_data	ft_input(int fd, char *file)
{
	struct s_data	area;
	char			*newl;

	ft_init_s_data(&area);
	newl = get_next_line(fd);
	area.sep_line = ft_split(newl, ' ');
	while (area.sep_line[area.lx])
	{
		free (area.sep_line[area.lx]);
		area.lx++;
	}
	free (area.sep_line);
	while (newl)
	{
		free(newl);
		newl = get_next_line(fd);
		area.ly++;
	}
	free(newl);
	close(fd);
	ft_malloc_xy(&area);
	ft_fill_xy(file, &area);
	return (area);
}

int	main(int argc, char **argv)
{
	int				fd;
	struct s_data	area;

	if (argc == 2 && ft_check_in(argv[1]))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			perror(NULL);
		else
		{
			area = ft_input(fd, argv[1]);
			ft_center(&area);
			ft_iso(&area);
			ft_put_img(&area);
		}
	}
	return (0);
}
