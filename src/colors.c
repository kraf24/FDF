/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:19:08 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/19 20:22:55 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"


void exeption(fdf *data, int y, int x, int y1, int x1)
{
	data->z = data->matrix[y][x];
	data->z1 = data->matrix[y1][x1];
	
	if (data->z == 2|| data->z1 == 2)
		data->color = 0x0000FF;
	else if (data->z == 1|| data->z1 == 1)
		data->color = 0x00FF00;
	else if (data->z == 3|| data->z1 == 3)
		data->color = 0x00FF00;
	else if (data->z > 5|| data->z1 > 5)
		data->color = 0x00FFFF;
	else
		data->color = 0x00FFFF;
}

void color(fdf *data, int y, int x, int y1, int x1)
{
	data->z = data->matrix[y][x];
	data->z1 = data->matrix[y1][x1];
	if(data->color_matrix[y][x])
	{
		data->color = data->color_matrix[y][x];
	}
	else
		exeption(data,y,x,y1,x1);
}

 int get_decimal(char hex)
{
	int i;

	i = 0;
	while ("0123456789abcdef"[i] != hex && "0123456789ABCDEF"[i] != hex)
	{
		//fprintf(stderr, "%c ", hex);
		if (i > 100)
			error("Invalid hex color value in map!");
		i++;
	}
	return (i);
}

int colors(char *temp)
{
	int i;
	int tem;
	int color;
	int counter;

	color = 0;
	counter = 0;
	i = 1;
	temp = ft_strnstr(temp, "0x", 8);
	if (temp != NULL)
	{
		temp += 2;
		counter = ft_strlen(temp);
		while(counter > 0)
		{
			tem = get_decimal(temp[--counter]);
			tem *= i;
			color += tem;
			i *= 16;
		}	
	}
	return (color);
}


