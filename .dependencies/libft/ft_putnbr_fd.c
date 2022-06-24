/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 13:40:59 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 14:59:26 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_num(int n, int fd)
{
	int		cont;
	int		keep_cont;
	char	num_inv[10];
	char	num[10];

	cont = 0;
	while (n != 0)
	{
		num_inv[cont] = 48 + n % 10;
		n = n / 10;
		cont++;
	}
	keep_cont = cont;
	cont = 1;
	while (cont <= keep_cont)
	{
		num[cont - 1] = num_inv[keep_cont - cont];
		cont++;
	}
	write(fd, num, keep_cont);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	ft_print_num(n, fd);
}
