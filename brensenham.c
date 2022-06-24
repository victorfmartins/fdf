/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brensenham.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:30:55 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 14:37:00 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fils_de_fer.h"

void	plot_xcase(t_line l, t_img *img)
{
	t_bresenham	b;
	int			color;

	b = (t_bresenham){l.x1 - l.x0, l.y1 - l.y0,
		2 * (l.y1 - l.y0) - (l.x1 - l.x0), l.x0, l.y0, 1};
	if (b.dy < 0)
		b = (t_bresenham){b.dx, -b.dy, -2 * b.dy - b.dx, l.x0, l.y0, -1};
	while (b.x <= l.x1)
	{
		color = get_color(l, l.x0, l.x1, b.x);
		img_pix_put(img, b.x, b.y, color);
		if (b.d > 0)
		{
			b.y = b.y + b.i;
			b.d = b.d + (2 * (b.dy - b.dx));
		}
		else
			b.d = b.d + 2 * b.dy;
		b.x ++;
	}
}

void	plot_ycase(t_line l, t_img *img)
{
	t_bresenham	b;
	int			color;

	b = (t_bresenham){l.x1 - l.x0, l.y1 - l.y0,
		2 * (l.x1 - l.x0) - (l.y1 - l.y0), l.x0, l.y0, 1};
	if (b.dx < 0)
		b = (t_bresenham){-b.dx, b.dy, -2 * b.dx - b.dy, l.x0, l.y0, -1};
	while (b.y <= l.y1)
	{
		color = get_color(l, l.y0, l.y1, b.y);
		img_pix_put(img, b.x, b.y, color);
		if (b.d > 0)
		{
			b.x = b.x + b.i;
			b.d = b.d + (2 * (b.dx - b.dy));
		}
		else
			b.d = b.d + 2 * b.dx;
		b.y ++;
	}
}

void	plot_line(t_line l, t_img *img)
{
	if (ft_abs(l.y1 - l.y0) < ft_abs(l.x1 - l.x0))
	{
		if (l.x0 > l.x1)
			plot_xcase((t_line){l.x1, l.x0, l.y1, l.y0, l.c1, l.c0}, img);
		else
			plot_xcase((t_line){l.x0, l.x1, l.y0, l.y1, l.c0, l.c1}, img);
	}
	else
	{
		if (l.y0 > l.y1)
			plot_ycase((t_line){l.x1, l.x0, l.y1, l.y0, l.c1, l.c0}, img);
		else
			plot_ycase((t_line){l.x0, l.x1, l.y0, l.y1, l.c0, l.c1}, img);
	}
}
