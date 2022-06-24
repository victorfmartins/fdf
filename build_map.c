/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:47:06 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 17:09:46 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fils_de_fer.h"

int	xlen(char *line)
{
	char	*trrimed_line;
	char	**numbers;
	int		i;

	trrimed_line = ft_strtrim(line, "\n ");
	numbers = ft_split(trrimed_line, ' ');
	i = 0;
	while (numbers && numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(trrimed_line);
	free(numbers);
	return (i);
}

void	close_gnl(char **line, int fd)
{
	while (*line)
	{
		free(*line);
		*line = get_next_line_bonus(fd);
	}
	free(*line);
}

int	get_extreme_coordinates(int *xmax, int *ymax, int fd)
{
	char	*line;
	char	*trrimed_line;

	if (fd == -1)
		return (0);
	*ymax = 1;
	*xmax = 0;
	line = get_next_line_bonus(fd);
	trrimed_line = ft_strtrim(line, "\n ");
	while (line && *trrimed_line != '\0')
	{
		if (xlen(line) > (*xmax))
			(*xmax) = xlen(line);
		*ymax += 1;
		free(line);
		free(trrimed_line);
		line = get_next_line_bonus(fd);
		trrimed_line = ft_strtrim(line, "\n ");
	}
	close_gnl(&line, fd);
	free(trrimed_line);
	return (1);
}

int	**get_line_numbers(char *line, int xmax)
{
	char	**numbers;
	int		i;
	int		**numb_array;

	numb_array = ft_calloc(xmax + 1, sizeof(int *));
	if (!numb_array)
		return (NULL);
	numbers = ft_split(line, ' ');
	i = 0;
	while (numbers && numbers[i])
	{
		numb_array[i] = malloc(sizeof(int));
		*(numb_array[i]) = ft_atoi(numbers[i]);
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (numb_array);
}

int	build_structure(int ****arr, int x, int y, int fd)
{
	char	*line;
	char	*trrimed_line;
	int		i;

	*arr = ft_calloc(y, sizeof(int **));
	if (!(*arr) || fd == -1)
		return (0);
	i = 0;
	line = get_next_line_bonus(fd);
	trrimed_line = ft_strtrim(line, "\n ");
	while (line && *trrimed_line != '\0')
	{
		(*arr)[i] = get_line_numbers(trrimed_line, x);
		if (!(*arr)[i])
			return (0);
		i++;
		free(line);
		free(trrimed_line);
		line = get_next_line_bonus(fd);
		trrimed_line = ft_strtrim(line, "\n ");
	}
	close_gnl(&line, fd);
	free(trrimed_line);
	(*arr)[i] = ft_calloc(x + 1, sizeof(int *));
	return (1);
}
