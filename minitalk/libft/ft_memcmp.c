/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abolea <abolea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:11:29 by abolea            #+#    #+#             */
/*   Updated: 2023/11/20 18:15:15 by abolea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*tmp1;
	unsigned char		*tmp2;

	i = 0;
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (n != 0)
	{
		if (tmp1[i] != tmp2[i])
			return (tmp1[i] - tmp2[i]);
		i++;
		n--;
	}
	return (0);
}
