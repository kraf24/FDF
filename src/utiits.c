/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:04:40 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/20 19:40:57 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

void	my_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x < data->win_width && y <= data->win_height && x > 0 && y > 0)
	{
		dst = data->addr + (y * data->line_length + \
					x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	fill(int x, int y, fdf *data)
{
	data->x = x;
	data->y = y;
}

void	free_2dstring(int **matrix, fdf *data)
{
	int	y;

	y = 0;
	while (y < data->height)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
}

int	**fill_matrix(int height, int width)
{
	int	i;
	int	**data;

	i = 0;
	data = (int **)ft_calloc(sizeof(int *), (height + 1));
	while (i < height)
	{
		data[i++] = (int *)ft_calloc(sizeof(int), (width + 1));
	}
	return (data);
}

void	isometric_y(int x, int y, fdf *data)
{
	fill(x, y, data);
	data->y1 = y + 1;
	data->x1 = x;
	color(data);
	data->x *= data->zoom;
	data->x1 *= data->zoom;
	data->y *= data->zoom;
	data->y1 *= data->zoom;
	data->z *= data->zoom_height;
	data->z1 *= data->zoom_height;
	rotate_x(&data->y, &data->z, data->x_angle);
	rotate_x(&data->y1, &data->z1, data->x_angle);
	rotate_y(&data->x, &data->z, data->y_angle);
	rotate_y(&data->x1, &data->z1, data->y_angle);
	rotate_z(&data->x, &data->y, data->z_angle);
	rotate_z(&data->x1, &data->y1, data->z_angle);
	if (data->project == true)
	{
		xy_isometric(&data->x, &data->y, data->z);
		xy_isometric(&data->x1, &data->y1, data->z1);
	}
	draw_line(data);
}
