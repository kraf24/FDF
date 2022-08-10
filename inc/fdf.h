/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:12:58 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/07/20 19:46:19 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef enum bool
{
	false,
	true
}					t_bool;

typedef struct s_mouse
{
	t_bool				is_pressed;
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
}						t_mouse;

typedef struct s_fdf
{
	void	*mxl;
	void	*mlx_win;
	int		**matrix;
	int		**color_matrix;
	int		width;
	int		height;

	float	zoom;
	float	angle;
	t_bool	project;
	float	zoom_height;
	int		color;
	int		y_start_point;
	int		x_start_point;
	int		constant;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		x;
	int		y;
	int		x1;
	int		y1;
	int		z;
	int		z1;
	double	z_angle;
	double	y_angle;
	double	x_angle;

	int		win_width;
	int		win_height;
	t_mouse	*mouse;
}			fdf;

void	print_int2dstr(int **str, int height, int width);
void	print_char2dstr(char ***str, int height, int width);

int		**get_map(char *name, fdf *data);
int		error(char *msg);

void	color(fdf *data);
void	isometric_x(int x, int y, fdf *data);
void	isometric_y(int x, int y, fdf *data);

void	my_mlx_pixel_put(fdf *data, int x, int y, int color);
void	free_2dstring(int **matrix, fdf *data);

void	draw_line(fdf *data);
void	draw_map(fdf *data);

int		key(int key, fdf *data);
void	zoom_key(int key, fdf *data);
void	zoom_height(int key, fdf *data);
void	move_key(int key, fdf *data);
int		escape(fdf *data);
void	claculations(fdf *data);
void	fill(int x, int y, fdf *data);
void	change_project(int key, fdf *data);

int		mous_press(int button, int x, int y, fdf *data);
int		mous_release(int button, int x, int y, fdf *data);
int		mous_move(int x, int y, fdf *data);

int		colors(char *temp);
int		**fill_matrix(int height, int width);
char	***color_matrix(int height, int width);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *x, int *y, double gamma);
void	rotate_x(int *y, int *z, double alpha);
void	xy_isometric(int *x, int *y, int z);
#endif