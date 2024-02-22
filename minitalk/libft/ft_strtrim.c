/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:55:05 by abolea            #+#    #+#             */
/*   Updated: 2023/11/14 13:38:12 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char s1, char const *set)
{
	char			s2;
	size_t			i;

	i = 0;
	s2 = s1;
	while (set[i])
	{
		if (s2 == set[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*s2;
	size_t		i;
	size_t		j;

	i = 0;
	j = ft_strlen(s1);
	if (!s1)
		return (NULL);
	s2 = (char *)s1;
	if (!set)
		return (s2);
	while (ft_isset(s2[i], set) == 0)
		i++;
	while (ft_isset(s2[j - 1], set) == 0)
		j--;
	return (ft_substr(s2, i, j - i));
}
