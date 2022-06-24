/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:30:08 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 14:37:06 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fils_de_fer.h"

int	get_color(t_line l, int start, int end, int current)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (l.c0 == l.c1)
		return (l.c0);
	if (start == end)
		percentage = 1.0;
	else
		percentage = ((double)(current - start) / (double)(end - start));
	red = (int)((1 - percentage)
			* ((l.c0 >> 16) & 0xFF) + percentage
			* ((l.c1 >> 16) & 0xFF));
	green = (int)((1 - percentage)
			* ((l.c0 >> 8) & 0xFF) + percentage
			* ((l.c1 >> 8) & 0xFF));
	blue = (int)((1 - percentage)
			* (l.c0 & 0xFF) + percentage * (l.c1 & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}

int	color_scale(int z, int zmin, int zmax)
{
	double	percentage;

	if (zmax == zmin)
		percentage = 1.0;
	else
		percentage = ((double)(z - zmin) / (double)(zmax - zmin));
	if (percentage < 0.2)
		return (0xffd7ef);
	else if (percentage < 0.4)
		return (0xffc2c0);
	else if (percentage < 0.6)
		return (0xffc569);
	else if (percentage < 0.8)
		return (0xf1e300);
	else
		return (0x05ff00);
}
