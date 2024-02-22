/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:58:20 by abolea            #+#    #+#             */
/*   Updated: 2023/11/20 18:17:40 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	i = 0;
	if ((ptr2[i] == '\0' && ptr1[i] == '\0') || n == 0)
		return (0);
	while (ptr1[i] == ptr2[i] && i < n - 1 && ptr1[i])
		i++;
	return (ptr1[i] - ptr2[i]);
}
