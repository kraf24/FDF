/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:13:52 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/06/25 17:06:38 by gpinchuk         ###   ########.fr       */
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

int	wd_counter(char *str)
{
	int	count;
	int	ind;
	int	i;

	count = 0;
	i = 0;
	ind = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') && ind == 0)
		{
			count++;
			ind = 1;
		}
		else
			ind = 0;
		i++;
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

void	matrix(int *matrix_line, char *string)
{
	char	**temp;
	int		i;

	temp = ft_split(string, ' ');
	i = 0;
	while (temp[i])
	{
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
	data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
		data->matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	fd = open(name, O_RDONLY, 0);
	// if (fd == -1)
	// {
		
	// }
	i = 0;
	while (i < data->height)
	{
		string = get_next_line(fd);
		matrix(data->matrix[i], string);
		free(string);
		i++;
	}
	data->matrix[i] = NULL;
	close(fd);
	return (data->matrix);
}
