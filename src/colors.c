/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:19:08 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/20 18:55:43 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

void	exeption(fdf *data)
{
	data->z = data->matrix[data->y][data->x];
	data->z1 = data->matrix[data->y1][data->x1];
	if (data->z == 2 || data->z1 == 2)
		data->color = 0x0000FF;
	else if (data->z == 1 || data->z1 == 1)
		data->color = 0x00FF00;
	else if (data->z == 3 || data->z1 == 3)
		data->color = 0x00FF00;
	else if (data->z > 5 || data->z1 > 5)
		data->color = 0x00FFFF;
	else
		data->color = 0x00FFFF;
}

void	color(fdf *data)
{
	data->z = data->matrix[data->y][data->x];
	data->z1 = data->matrix[data->y1][data->x1];
	if (data->color_matrix[data->y][data->x])
		data->color = data->color_matrix[data->y][data->x];
	else
		exeption(data);
}

int	get_decimal(char hex)
{
	int	i;

	i = 0;
	while ("0123456789abcdef"[i] != hex && "0123456789ABCDEF"[i] != hex)
	{
		if (i > 100)
			error("Invalid hex color value in map!");
		i++;
	}
	return (i);
}

int	colors(char *temp)
{
	int	i;
	int	tem;
	int	color;
	int	counter;

	color = 0;
	counter = 0;
	i = 1;
	temp = ft_strnstr(temp, "0x", 8);
	if (temp != NULL)
	{
		temp += 2;
		counter = ft_strlen(temp);
		if (ft_strnstr(temp, "\n", 8))
			counter -= 1;
		while (counter > 0)
		{
			tem = get_decimal(temp[--counter]);
			tem *= i;
			color += tem;
			i *= 16;
		}	
	}
	return (color);
}
