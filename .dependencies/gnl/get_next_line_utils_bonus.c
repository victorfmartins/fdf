/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:18:26 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 13:11:51 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr2(const char *s, int c)
{
	if (!s)
		return (NULL);
	c = (unsigned char) c;
	while (*s != c && *s != '\0')
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup2(const char *s1)
{
	char	*s2;
	size_t	n;
	size_t	i;

	if (!s1)
		return (NULL);
	n = ft_strlen2(s1);
	s2 = malloc(sizeof(char) * n + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)s2)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	((unsigned char *)s2)[i] = '\0';
	return (s2);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*join;

	len_s1 = ft_strlen2(s1);
	len_s2 = ft_strlen2(s2);
	join = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (i++ < len_s1)
		join[i - 1] = s1[i - 1];
	i = 0;
	while (i++ < len_s2)
		join[i + len_s1 - 1] = s2[i - 1];
	join[len_s1 + len_s2] = '\0';
	return (join);
}

size_t	ft_strlcpy2(char *dst, const char *src, size_t size)
{
	size_t	idx;

	if (!src)
		return (0);
	if (size == 0)
		return (ft_strlen2((char *)src));
	idx = 0;
	while (src[idx] != '\0' && idx < size - 1)
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (ft_strlen2(src));
}

size_t	ft_strlen2(const char *str)
{
	size_t	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}
