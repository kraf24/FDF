/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:50:11 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/19 19:23:33 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include "fdf.h"

int	escape(fdf *data)
{
	mlx_destroy_window(data->mxl, data->mlx_win);
	mlx_destroy_image(data->mxl, data->img);
	if(data->matrix)
	{
	fprintf(stderr, "dfgf");
	free_2dstring(data);
	}
	free(data->mouse);
	free(data);
	exit(1);
}
