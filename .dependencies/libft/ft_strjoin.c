/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 08:36:10 by vfranco-          #+#    #+#             */
/*   Updated: 2022/06/13 15:00:01 by vfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	len_s1;
	unsigned int	len_s2;
	char			*join;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
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
