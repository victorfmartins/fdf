/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:32:34 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 17:14:44 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fils_de_fer.h"

t_line	get_iso(t_data *data, int x, int y, int z)
{
	t_line	line;

	line.x0 = 50 + round(cos(0.7854) * x + sin(0.7854) * y);
	line.y0 = 380 + round((sin(0.7854) * x - cos(0.7854) * y - z) / 2);
	line.c0 = color_scale(z, data->sttr.zmin, data->sttr.zmax);
	return (line);
}

int	render_line(t_img *img, t_line line)
{
	plot_line(line, img);
	return (0);
}

void	render_extremes(t_data *data, int d, int i, int j)
{
	t_line	l0;
	t_line	l1;

	if (j < data->sttr.xmax - 1 && i == data->sttr.ymax - 2
		&& data->sttr.arr[i][j] && data->sttr.arr[i][j + 1])
	{
		l0 = get_iso(data, d * i, d * j, data->sttr.arr[i][j][0]);
		l1 = get_iso(data, d * i, d * (j + 1), data->sttr.arr[i][j + 1][0]);
		render_line(&data->img, (t_line){l0.x0, l1.x0, l0.y0, l1.y0, l0.c0,
			l1.c0});
	}
	if (j == data->sttr.xmax - 1 && i < data->sttr.ymax - 2
		&& data->sttr.arr[i][j] && data->sttr.arr[i + 1][j])
	{
		l0 = get_iso(data, d * i, d * j, data->sttr.arr[i][j][0]);
		l1 = get_iso(data, d * (i + 1), d * j, data->sttr.arr[i + 1][j][0]);
		render_line(&data->img, (t_line){l0.x0, l1.x0, l0.y0, l1.y0, l0.c0,
			l1.c0});
	}
}

void	render_inside(t_data *data, int d, int i, int j)
{
	t_line	l0;
	t_line	l1;

	if (j < data->sttr.xmax - 1 && i < data->sttr.ymax - 2)
	{
		if (data->sttr.arr[i][j] && data->sttr.arr[i][j + 1])
		{
			l0 = get_iso(data, d * i, d * j, data->sttr.arr[i][j][0]);
			l1 = get_iso(data, d * i, d * (j + 1), data->sttr.arr[i][j + 1][0]);
			render_line(&data->img, (t_line){l0.x0, l1.x0, l0.y0, l1.y0, l0.c0,
				l1.c0});
		}
		if (data->sttr.arr[i][j] && data->sttr.arr[i + 1][j])
		{
			l0 = get_iso(data, d * i, d * j, data->sttr.arr[i][j][0]);
			l1 = get_iso(data, d * (i + 1), d * j, data->sttr.arr[i + 1][j][0]);
			render_line(&data->img, (t_line){l0.x0, l1.x0, l0.y0, l1.y0, l0.c0,
				l1.c0});
		}
	}
}

int	render(t_data *data)
{
	int		i;
	int		j;
	int		d;

	if (data->win_ptr == NULL)
		return (1);
	i = 0;
	while (i < data->sttr.ymax)
	{
		j = 0;
		d = ft_min((WINDOW_HEIGHT / data->sttr.ymax),
				WINDOW_WIDTH / data->sttr.xmax);
		while (j < data->sttr.xmax)
		{
			render_inside(data, d, i, j);
			render_extremes(data, d, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0,
		0);
	return (0);
}
