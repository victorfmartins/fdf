/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:04:01 by vfranco-          #+#    #+#             */
/*   Updated: 2022/05/21 17:06:38 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fils_de_fer.h"

int	xlen(char *line)
{
	int		idx;
	int		xmax;

	xmax = 0;
	idx = 0;
	while (line[idx])
	{
		if (ft_isdigit(line[idx]))
		{
			xmax++;
			while(ft_isdigit(line[idx]))
				idx++;
		}
		else
			idx++;
		// while ((line[idx] >= 9 && line[idx] <= 13) || line[idx] == 32)
		// 	idx++;
	}
	return (xmax);
}

int	**get_line_numbers(int **arr, char *line, int xmax)
{
	int		idx;
	int		x;

	arr = ft_calloc(xmax + 1, sizeof(int *));
	if (!arr)
	{
		printf("unable to create arr of int of size %d", xmax + 1);
		return(NULL);
	}
	x = 0;
	idx = 0;
	while (idx <= (int)ft_strlen(line))
	{
		if (ft_isdigit(line[idx]))
		{
			arr[x] = malloc(sizeof(int));
			*(arr[x]) = ft_atoi(&line[idx]);
			x++;
			while (ft_isdigit(line[idx]))
				idx++;
			while ((line[idx] >= 9 && line[idx] <= 13) || line[idx] == 32)
				idx++;
			while (line[idx] == '-' || line[idx] == '+')
				idx++;
		}
		else
			idx++;
	}
	return (arr);
}

void	print_from_structure(int ***arr, int xmax, int ymax)
{
	int i = 0;
	int j = 0;
	
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

int	get_extreme_coordnates(char *argv, int *xmax, int *ymax) // faltou um I no coordinates
{
	char	*line;
	int		fd;
	
	line = ft_strdup(argv);
	fd = open(line, O_RDONLY); // podia passar argv direto aqui
	if (!line || fd == -1)
		return(0);
	free(line);
	*ymax = 0;
	*xmax = 0;
	while (++(*ymax))
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (xlen(line) > (*xmax))
			(*xmax) = xlen(line);
		free(line);
	}
	free(line);
	close(fd);
	return (1);
}

int	build_structure(int ****arr, int *x, int *y, char *argv)
{
	char	*line;
	int		fd;
	
	*arr = ft_calloc(*y, sizeof(int **));
	line = ft_strdup(argv);
	fd = open(line, O_RDONLY);
	if (!(*arr) || !line || fd == -1)
		return (0);
	free(line);
	*y = 0;
	while (++(*y))
	{
		line = get_next_line(fd);
		if (!line)
			break;
		(*arr)[(*y)-1] = get_line_numbers((*arr)[(*y)-1], line, (*x));
		if (!(*arr)[(*y)-1])
			return (0);
		free(line);
	}
	(*arr)[(*y)-1] = ft_calloc((*x) + 1, sizeof(int *)); // creating a buffer below (is it necessary?)
	free(line);
	close(fd);
	return (1);
}

int	check_arguments(int argc, char **argv) // não testada
{
	int	len;

	len = ft_strlen(argv[argc - 1]);
	if (len < 5 || argc != 2) // argc must be 2 and argc[1] must contain at least 5 char: *.fdf
		return (0);
	if (ft_strncmp(&argv[1][len - 4], ".fdf", 4)) // the last four must be .fdf
		return (0);
	return (1);
}

int	gnl_main(int argc, char **argv, t_data *data)
{
	if (!check_arguments(argc, argv))
		return (0);
	printf("Map file is: %s\n", argv[1]);
	if (get_extreme_coordnates(argv[1], &(data->sttr.xmax), &(data->sttr.ymax)) == 0)
		return (0);
	if (build_structure(&(data->sttr.arr), &(data->sttr.xmax), &(data->sttr.ymax), argv[1]) == 0)
		return(0);
	print_from_structure(data->sttr.arr, data->sttr.xmax, data->sttr.ymax);
	return (1);
}