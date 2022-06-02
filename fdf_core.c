/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:43:51 by coder             #+#    #+#             */
/*   Updated: 2022/05/23 02:12:58 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fils_de_fer.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

// void	get_color(t_data data)
// {
	
// }

void	plotXcase(t_line l, t_img *img)
{
	t_bresenham	b;

	// put x an y out of any strucure to test performance
	b = (t_bresenham){ l.x1 - l.x0, l.y1 - l.y0, 2 * (l.y1 - l.y0) - l.x1 - l.x0, 
																l.x0, l.y0, 1};
	if (b.dy < 0)
		b = (t_bresenham){ b.dx, -b.dy, -2 * b.dy - b.dx, l.x0, l.y0, -1};
	while (b.x < l.x1)
	{
		// get_color(data, l.x, l.y, );
		img_pix_put(img, b.x, b.y, l.color);
		if (b.D > 0)
		{
			b.y = b.y + b.i;
			b.D = b.D + (2 * (b.dy - b.dx));
		}
		else
			b.D = b.D + 2 * b.dy;
		b.x ++;
	}
}

void	plotYcase(t_line l, t_img *img)
{
	t_bresenham	b;

	// put x an y out of any strucure to test performance
	b = (t_bresenham){ l.x1 - l.x0, l.y1 - l.y0, 2 * (l.x1 - l.x0) - l.y1 - l.y0, 
																l.x0, l.y0, 1};
	if (b.dx < 0)
		b = (t_bresenham){ -b.dx, b.dy, -2 * b.dx - b.dy, l.x0, l.y0, -1};
	while (b.y < l.y1)
	{
		img_pix_put(img, b.x, b.y, l.color);
		if (b.D > 0)
		{
			b.x = b.x + b.i;
			b.D = b.D + (2 * (b.dx - b.dy));
		}
		else
			b.D = b.D + 2 * b.dx;
		b.y ++;
	}
}

void	plotLine(t_line line, t_img *img)
{
	if (abs(line.y1 - line.y0) < abs(line.x1 - line.x0))
	{
		if (line.x0 > line.x1)
			plotXcase((t_line){line.x1, line.x0, line.y1, line.y0, line.color}, img);
		else
			plotXcase((t_line){line.x0, line.x1, line.y0, line.y1, line.color}, img);
	}
	else
	{
		if (line.y0 > line.y1)
			plotYcase((t_line){line.x1, line.x0, line.y1, line.y0, line.color}, img);
		else
			plotYcase((t_line){line.x0, line.x1, line.y0, line.y1, line.color}, img);
	}
}

int	render_line(t_img *img, t_line line)
{
	plotLine(line, img);
	return (0);
}

t_line	get_iso(int x, int y, int z)
{
	t_line	line;

	line.x0 = round(cos(0.7854) * x - sin(0.7854) * y);
	line.y0 = round((sin(0.7854) * x + cos(0.7854) * y - z) / 2);
	return (line);
}

int	render(t_data *data)
{
	int		i;
	int		j;
	int s;
	// t_line	l0;
	// t_line	l1;
	
	if (data->win_ptr == NULL)
		return (1);
	i = 0;
	while (i < data->sttr.ymax)
	{
		j = 0;
		while (j < data->sttr.xmax)
		{
			// if ultima linha
			// 	print right only
			// else if ultima coluna
			// 	print down only
			// else
				// print down and rigth --> caso pra fazer hj:
			// printf("%d", data->sttr.arr[i][j][0]);
			// printf("(%d,%d) ", (get_iso(i, j, data->sttr.arr[i][j][0])).x0, (get_iso(i, j, data->sttr.arr[i][j][0])).y1);
			// if (j < data->sttr.xmax - 1 && i < data->sttr.ymax - 1)
			// {
			// 	l0 = get_iso(i, j, data->sttr.arr[i][j][0]); //ponto atual
			// 	l1 = get_iso(i, j + 1, data->sttr.arr[i][j + 1][0]); //ponto a direita
			// 	// render_line(&data->img, (t_line){l0.x0, l1.x0, l0.y0, l1.y0, RED});
			// 	// l1 = get_iso(i + 1, j, data->sttr.arr[i + 1][j][0]); //ponto a baixo
			// 	// render_line(&data->img, (t_line){l0.x0, l1.x0, l0.y0, l1.y0, RED});
			// }
			
			// functional code for ploting ortogonal grid
			s = WINDOW_WIDTH * 0.8 / data->sttr.xmax;
			if (j < data->sttr.xmax - 1 && i < data->sttr.ymax - 1)
				render_line(&data->img, (t_line){round(WINDOW_WIDTH * 0.1 + s * j) //s = WINDOW_WIDTH * 0.8 / data->sttr.xmax
												,round(WINDOW_WIDTH * 0.1 + s * (j+1))
												,round(WINDOW_HEIGHT * 0.1 + s * i)
												,round(WINDOW_HEIGHT * 0.1 + s * i)
												,RED});
			if (i < data->sttr.ymax - 2)
				render_line(&data->img, (t_line){round(WINDOW_WIDTH * 0.1 + s * j)
												,round(WINDOW_WIDTH * 0.1 + s * j)
												,round(WINDOW_HEIGHT * 0.1 + s * i)
												,round(WINDOW_HEIGHT * 0.1 + s * (i+1))
												,RED});
			j++;
		}
		i++;
		printf("\n");
	}
	// render_line(&data->img, (t_line){100, 500, 200, 100, RED});

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

void	print_from_structure2(int ***arr, int xmax, int ymax)
{
	int i = 0;
	int j = 0;
	
	printf("\n%d\t%d\n", ymax, xmax);
	while (i <= ymax - 1)
	{
		j = 0;
		while (j <= xmax) // da pra por mais um (indevidamente ?)
		{
			if (*(*(arr + i) + j))
				printf("%d ", *(*(*(arr + i) + j)));
			else
				printf("n ");
			j++;
			// free(*(*(arr + i) + j)); //free(arr[ymax][xmax]) 
			// cannot give free both ways. left one because how can i look after a cell that i gave free (?)
		}
		printf("\n");
		i++;
		// free(*(arr + i)); //free(arr[ymax])
	}
	// free(arr);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (gnl_main(argc, argv, &data) == 0)
	{
		printf("error");
		return (MLX_ERROR);
	}
	printf("\n\n");
	print_from_structure2(data.sttr.arr, data.sttr.xmax, data.sttr.ymax);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); // destroynotify event to apply exit by pressing x

	mlx_loop(data.mlx_ptr);

	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	/* Optional, just clears window by turning it all black*/
	// mlx_clear_window ( void *mlx_ptr, void *win_ptr )
	/* Destroys window */
	// mlx_destroy_window ( void *mlx_ptr, void *win_ptr )
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}