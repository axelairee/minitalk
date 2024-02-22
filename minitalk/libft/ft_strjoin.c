/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:22:07 by abolea            #+#    #+#             */
/*   Updated: 2023/11/20 18:17:15 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (ft_strdup(""));
	s3 = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!s3)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
		s3[i++] = s2[j++];
	return (s3);
}
