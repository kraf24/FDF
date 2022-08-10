/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:27:29 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/20 17:25:33 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

int	mous_press(int button, int x, int y, fdf *data)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
		zoom_key(button, data);
	else if (button == 1)
		data->mouse->is_pressed = true;
	return (0);
}

int	mous_release(int button, int x, int y, fdf *data)
{
	(void)x;
	(void)y;
	(void)button;
	data->mouse->is_pressed = false;
	return (0);
}

int	mous_move(int x, int y, fdf *data)
{
	data->mouse->previous_x = data->mouse->x;
	data->mouse->previous_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	if (data->mouse->is_pressed == true)
	{
		data->x_angle += (data->mouse->previous_x - data->mouse->x) * 0.002;
		data->y_angle += (data->mouse->previous_y - data->mouse->y) * 0.002;
		draw_map(data);
	}
	return (0);
}
