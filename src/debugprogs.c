/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugprogs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:15:26 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/06/08 12:21:24 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

void print_int2dstr(int **str, int height, int width)
{
	int x = 0;
	int y = 0;

	while(y < height)
	{
		x = 0;
		while(x < width)
		{
			fprintf(stderr, "%d ", str[y][x]);
			x++;
		}
		fprintf(stderr, "%c", '\n');
		y++;
	}
}