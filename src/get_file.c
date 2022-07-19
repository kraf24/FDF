/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:13:52 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/19 20:24:34 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <libft.h>
#include <mlx.h>
#include "get_next_line.h"

int	get_height(char *name)
{
	int	height;
	int	fd;
	char *temp;

	height = 0;
	fd = open(name, O_RDONLY, 0);
	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		height++;
		temp = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	wd_counter(char *str) //not working
{
	int	count;
	char **strd;

	count = 0;
	strd = ft_split(str, ' ');
	while(strd[count])
	{
		if(ft_strncmp(strd[count], "\n", 5) == 0)
		return (count - 1);
		count++;
	}
	return (count);
}

int	get_width(char *name)
{
	int		width;
	int		fd;
	char	*str;

	width = 0;
	fd = open(name, O_RDONLY, 0);
	str = get_next_line(fd);
	width = wd_counter(str);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		free(str);
	}
	close(fd);
	return (width);
}

void matrix(int *matrix_line, int *cmatrix_line, char *string)
{
	char	**temp;
	int		i;
	
	temp = ft_split(string, ' ');
	i = 0;
	while (temp[i])
	{
		cmatrix_line[i] = colors(temp[i]);
		matrix_line[i] = ft_atoi(temp[i]);
		free(temp[i]);
		i++;
	}
	free(temp);
}

int	**get_map(char *name, fdf *data)
{
	int		fd;
	char	*string;
	int		i;

	data->height = get_height(name);
	data->width = get_width(name);
	data->color_matrix = fill_matrix(data->height, data->width);
	data->matrix = fill_matrix(data->height, data->width);
	fd = open(name, O_RDONLY, 0);
	i = 0;
	while (i < data->height)
	{
		string = get_next_line(fd);
		matrix(data->matrix[i],data->color_matrix[i], string);
		free(string);
		i++;
	}
	data->matrix[i] = NULL;
	data->color_matrix[i] = NULL;
	print_int2dstr(data->color_matrix, data->height ,data->width);
	//print_int2dstr(data->matrix, data->height ,data->width);
	close(fd);
	
	return (data->matrix);
}
