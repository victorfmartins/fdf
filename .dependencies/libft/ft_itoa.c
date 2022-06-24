/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:40:05 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 14:58:20 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		size;
	int		result;

	size = (n <= 0);
	result = n;
	while (result != 0)
	{
		result = result / 10;
		size++;
	}
	s = malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	s[size] = '\0';
	s[0] = '-' * (n < 0) + '0' * (n == 0);
	while (n != 0)
	{
		result = n % 10 * ((n > 0) - (n < 0));
		n /= 10;
		s[size - 1] = '0' + result;
		size--;
	}
	return (s);
}
