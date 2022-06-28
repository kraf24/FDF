/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:19:08 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/06/15 17:24:20 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

void color(fdf *data, int y, int x, int y1, int x1)
{
	data->z = data->matrix[y][x];
	data->z1 = data->matrix[y1][x1];
	
	if (data->z == 2|| data->z1 == 2)
		data->color = 0x0000FFFF;
	else if (data->z == 1|| data->z1 == 1)
		data->color = 0x00FF0000;
	else if (data->z == 3|| data->z1 == 3)
		data->color = 0x00FF00FF;
	else if (data->z > 5|| data->z1 > 5)
		data->color = 0x00FFFF00;
	else
		data->color = 0x00FFFFFF;
}