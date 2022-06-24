/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:04:01 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 17:09:57 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fils_de_fer.h"

void	get_z_extremes(int ***arr, t_extr *sttr)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 0;
	sttr->zmin = 0;
	sttr->zmax = 0;
	while (i < sttr->ymax - 1)
	{
		j = 0;
		while (j < sttr->xmax && arr[i][j])
		{			
			z = arr[i][j][0];
			if (z && z < sttr->zmin)
				sttr->zmin = z;
			if (z && z > sttr->zmax)
				sttr->zmax = z;
			j++;
		}
		i++;
	}
}

int	check_arguments(int argc, char **argv)
{
	int	len;

	len = ft_strlen(argv[argc - 1]);
	if (len < 5 || argc != 2)
		return (0);
	if (ft_strncmp(&argv[1][len - 4], ".fdf", 4))
		return (0);
	return (1);
}

int	read_map(int argc, char **argv, t_data *data)
{
	int	fd1;
	int	fd2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[1], O_RDONLY);
	if (!check_arguments(argc, argv))
		return (0);
	if (get_extreme_coordinates(&(data->sttr.xmax),
			&(data->sttr.ymax), fd1) == 0)
		return (0);
	if (build_structure(&(data->sttr.arr), (data->sttr.xmax),
			(data->sttr.ymax), fd2) == 0)
		return (0);
	get_z_extremes(data->sttr.arr, &(data->sttr));
	close(fd1);
	close(fd2);
	return (1);
}
