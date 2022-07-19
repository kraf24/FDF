/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:04:40 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/17 17:57:12 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

void	my_mlx_pixel_put(fdf *data, int x, int y, int color)
{
	char *dst;
	if ((x < data->win_width && y <= data->win_height) && ( x > 0 && y > 0))
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
void fill(int x, int y, int x1, int y1, fdf *data)
{
	data->x = x;
	data->x1 = x1;
	data->y = y;
	data->y1 = y1;
}

void free_2dstring(fdf *data)
{
	int y = 0;

	while(y < data->height)
	{
		free(data->matrix[y]);
		y++;
	}
	free(data->matrix);
}

int **fill_matrix(int height, int width)
{
	int i;
	int **data;

	i = 0;
	data = (int **)ft_calloc(sizeof(int *), (height + 1));
	while (i < height)
	{
		data[i++] = (int *)ft_calloc(sizeof(int), (width + 1));
	}
	return (data);
}