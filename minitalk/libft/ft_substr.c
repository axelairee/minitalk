/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:09:58 by abolea            #+#    #+#             */
/*   Updated: 2023/11/20 18:17:56 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*s2;
	unsigned int	i;
	size_t			len_s;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	s2 = ft_calloc((len + 1), sizeof(char));
	if (!s2)
		return (NULL);
	while (len--)
		s2[i++] = s[start++];
	return (s2);
}
