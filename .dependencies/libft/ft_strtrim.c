/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:12:37 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 15:00:36 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		beg;
	int		end;
	int		i;
	char	*s_copy;

	beg = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	while (end > beg && ft_strchr(set, s1[end - 1]))
		end--;
	i = 0;
	s_copy = malloc(sizeof(char) * (end - beg + 1));
	if (!s_copy)
		return (NULL);
	while (i < end - beg)
	{
		s_copy[i] = s1[beg + i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
