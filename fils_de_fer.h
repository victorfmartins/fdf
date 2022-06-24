/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fils_de_fer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:12:38 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 17:37:03 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILS_DE_FER_H
# define FILS_DE_FER_H
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "./.dependencies/libft/libft.h"
# include "./.dependencies/gnl/get_next_line_bonus.h"

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 600

# define MLX_ERROR 1

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_extr
{
	int	***arr;
	int	xmax;
	int	ymax;
	int	zmin;
	int	zmax;
}	t_extr;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		cur_img;
	t_img	img;
	t_extr	sttr;
}	t_data;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	c0;
	int	c1;
}	t_line;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	d;
	int	x;
	int	y;
	int	i;
}	t_bresenham;

int		main(int argc, char **argv);
int		read_map(int argc, char **argv, t_data *data);
int		render(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_no_event(void);
int		close_window(t_data *data);
void	plot_line(t_line l, t_img *img);
int		color_scale(int z, int zmin, int zmax);
int		get_color(t_line l, int start, int end, int current);
void	img_pix_put(t_img *img, int x, int y, int color);
int		build_structure(int ****arr, int x, int y, int fd);
int		get_extreme_coordinates(int *xmax, int *ymax, int fd);
#endif