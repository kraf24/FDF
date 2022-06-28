/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:53:56 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/06/25 16:38:55 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

int key(int key, fdf *data)
{
	printf("%d \n", key);
	if (key >= 123 && key <= 126)
		move_key(key , data);
	if (key == 30 || key == 44)
		zoom_key(key , data);
	if (key == 4 || key == 37)
		zoom_height(key, data);
	if (key == 3 || key == 11)
		change_project(key, data);
	if (key == 53)
	{
		free_2dstring(data);
		mlx_destroy_window(data->mxl, data->mlx_win);
		mlx_destroy_image(data->mxl,data->img);
		free(data->mouse);
		free(data);
		
		exit(1);
	}
	return (0);
}

void move_key(int key, fdf *data)
{
	if (key == 126)
		data->y_start_point -= 10;
	if (key == 125)
		data->y_start_point += 10;
	if (key == 124)
		data->x_start_point += 10;
	if (key == 123)
		data->x_start_point -= 10;
	draw_map(data);
}

void zoom_key(int key, fdf *data)
{
	if (key == 30)
		data->zoom += 0.5;
	if (key == 44)
	{
		if (data->zoom - 0.5 < 0)
			return;
		data->zoom -= 0.5;
	}
	if (key == 5)
		data->zoom += 0.5;
	if (key == 4)
	{
		if (data->zoom - 0.5 < 0)
			return;
		data->zoom -= 0.5;
	}
	draw_map(data);
}

void zoom_height(int key, fdf *data)
{
	if (key == 4)
	{
		if (data->zoom_height > 10)
			return;
		data->zoom_height += 0.1;
	}
	if (key == 37)
	{
		if (data->zoom_height - 0.1 < 0)
			return;
		data->zoom_height -= 0.1;
	}
	draw_map(data);
}

void change_project(int key, fdf *data)
{
	data->y_angle = 0;
	data->z_angle = 0;
	data->x_angle = 0;
	if (key == 3)
	{
		data->project = false;
	}
	if (key == 11)
	{
		data->project = true;
	}
	draw_map(data);
}