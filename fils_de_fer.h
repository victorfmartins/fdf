/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:12:38 by vfranco-          #+#    #+#             */
/*   Updated: 2022/05/22 18:10:53 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILS_DE_FER_H
# define FILS_DE_FER_H
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>
#include "./.dependencies/libft/libft.h"
#include "./.dependencies/gnl/get_next_line.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

#define RED 0xFF0000
#define GREEN 0xFF00
#define WHITE 0xFFFFFF

typedef struct s_img /*structure to hold important image related data*/
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_extr /*structure to hold important image related data*/
{
	int	***arr;
	int	xmax;
	int	ymax;
	int	zmin;
	int	zmax;
}	t_extr;

typedef struct s_data /* structure to hold all mlx objects in use*/
{
	void	*mlx_ptr; /*mlx instance*/
	void	*win_ptr; /*window pointer*/
	int		cur_img;  /*image id*/
	t_img	img;	  /*image structure*/
	t_extr	sttr;     /*project structure*/
}	t_data;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	color;
}	t_line;

// typedef struct s_point
// {
// 	int	x;
// 	int	y;
// 	int	color;
// }	t_point;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	D;
	int	x;
	int	y;
	int	i;
}	t_bresenham;

int	gnl_main(int argc, char **argv, t_data *data);
int	main(int argc, char **argv);
//int	render(t_data *data);

#endif