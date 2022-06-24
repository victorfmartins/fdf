/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:35:22 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 15:00:40 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	len_s;
	size_t	size;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	size = 0;
	while (start < len_s && s[start + size] && size < len)
		size++;
	s2 = malloc(sizeof(char) * size + 1);
	if (!s2)
		return (NULL);
	s2[size] = '\0';
	if (start < len_s)
		ft_strlcpy(s2, (char *)s + start, len + 1);
	return (s2);
}
