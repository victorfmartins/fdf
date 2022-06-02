/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 13:35:31 by vfranco-          #+#    #+#             */
/*   Updated: 2021/09/12 22:34:44 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (src < dst)
	{
		while (0 < n)
		{
			((unsigned char *)dst)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
