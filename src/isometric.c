/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:57:26 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/20 19:44:35 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	xy_isometric(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.9);
	*y = (*x + *y) * sin(0.9) - z;
}

void	isometric_x(int x, int y, fdf *data)
{
	fill(x, y, data);
	data->x1 = x + 1;
	data->y1 = y;
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
